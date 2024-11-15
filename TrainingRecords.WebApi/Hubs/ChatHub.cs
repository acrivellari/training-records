using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.SignalR;
using Newtonsoft.Json;
using TrainingRecords.Core.Services.Interfaces;
using TrainingRecords.Core.Dto;

namespace TrainingRecords.WebApi.Hubs;

[Authorize]
public class ChatHub : Hub
{
    private readonly IChatService _service;

    public ChatHub(IChatService service)
    {
        this._service = service;
    }

    public override Task OnConnectedAsync()
    {
        // Store connection ID
        _service.StoreConnection(Context.ConnectionId, Int32.Parse(Context.UserIdentifier));
        // Give back connection ID to the connected client
        Clients.Client(Context.ConnectionId).SendAsync("ReceiveConnID", Context.ConnectionId);
        // Get active chats room for the user
        var dto = _service.GetActiveRooms(Int32.Parse(Context.UserIdentifier));
        // Send to the client
        Clients.Client(Context.ConnectionId).SendAsync("ReceiveRoomsList", dto);
        // Return parent method
        return base.OnConnectedAsync();
    }

    public override Task OnDisconnectedAsync(Exception exception)
    {
        // Delete saved connection ID
        _service.ClearUserConnection(Int32.Parse(Context.UserIdentifier));
        return base.OnDisconnectedAsync(exception);
    }

    public async Task RefreshActiveRooms()
    {
        // Get active chats room for the user
        var dto = _service.GetActiveRooms(Int32.Parse(Context.UserIdentifier));
        // Send to the client
        await Clients.Client(Context.ConnectionId).SendAsync("ReceiveRoomsList", dto);
    }

    public async Task OpenChatRoom(string roomId)
    {
        if (roomId != null)
        {
            // Convert room ID from string to long
            long id = long.Parse(roomId);
            // Mark all messages as read by the user
            _service.ReadAllMessages(id, Int32.Parse(Context.UserIdentifier));
            // Get messages in conversation
            var roomConversation = _service.GetRoomConversation(id);
            // Send data to the client
            await Clients.Client(Context.ConnectionId).SendAsync("ReceiveConversation", roomConversation);
        }
    }

    public async Task ReadMessagesInRoom(string roomId)
    {
        // Convert room ID from string to long
        long id = long.Parse(roomId);
        // Mark all messages as read by the user
        _service.ReadAllMessages(id, Int32.Parse(Context.UserIdentifier));
        await Clients.Client(Context.ConnectionId).SendAsync("Empty");
    }

    public async Task SendMessageAsync(string messageOb)
    {
        var routeOb = JsonConvert.DeserializeObject<ChatMessageDto>(messageOb);
        routeOb.MessageDate = DateTime.Now;
        ChatMessageDto insertedMessage = _service.AddMessage(routeOb);
        List<ChatRoomMemberDto> list = _service.GetRoomMembers((long)routeOb.RoomId);
        foreach (ChatRoomMemberDto m in list)
        {
            if (m.UserId != Int32.Parse(Context.UserIdentifier))
            {
                await Clients.Client(m.ConnectionId).SendAsync("ReceiveMessage", insertedMessage);
            }
        }
    }

    public async Task SendFirstMessageAsync(string messageOb)
    {
        var routeOb = JsonConvert.DeserializeObject<ChatFirstMessageDto>(messageOb);
        routeOb.MessageDate = DateTime.Now;
        ChatMessageDto message = new ChatMessageDto();
        // If is the first message sent in a chat room the roomId will be null.
        // The system creates the room before save the message
        if (routeOb.RoomId == null)
        {
            // Create new room
            long newRoomId = _service.CreateRoom(null, Context.User.Identity.Name);
            // Add members to it
            foreach (int m in routeOb.UsersInRoom)
            {
                _service.AddMember(newRoomId, m, Context.User.Identity.Name);
            }
            // Create message object
            message.UserId = routeOb.UserId;
            message.RoomId = newRoomId;
            message.MessageContent = routeOb.MessageContent;
            message.MessageDate = routeOb.MessageDate;
        }
        ChatMessageDto insertedMessage = _service.AddMessage(message);
        List<ChatRoomMemberDto> list = _service.GetRoomMembers((long)message.RoomId);
        foreach (ChatRoomMemberDto m in list)
        {
            if (m.UserId != Int32.Parse(Context.UserIdentifier))
            {
                // Sends new message alert to all the clients connected to the room but the sender of the message
                await Clients.Client(m.ConnectionId).SendAsync("ReceiveMessage", insertedMessage);
            }
            else
            {
                // If is the first message created, sends back to the sender the ID of the room just created
                await Clients.Client(m.ConnectionId).SendAsync("NewRoomCreated", insertedMessage.RoomId);
            }
        }
    }
}