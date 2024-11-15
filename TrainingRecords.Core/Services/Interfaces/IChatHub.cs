using TrainingRecords.Core.Dto;

namespace TrainingRecords.Core.Services.Interfaces;

public interface IChatService
{
    /// <summary>
    /// Saves the connection ID of the connected user
    /// </summary>
    /// <param name="connectionId">Connection ID</param>
    /// <param name="userId">User ID</param>
    /// <returns>
    /// void
    /// </returns>
    void StoreConnection(string connectionId, int userId);

    /// <summary>
    /// Clears all connection IDs for the user passed as parameter
    /// </summary>
    /// <param name="userId">User's ID</param>
    /// <returns>
    /// void
    /// </returns>
    void ClearUserConnection(int userId);

    /// <summary>
    /// Returns the preview of the active chat rooms for the user passed as parameter
    /// </summary>
    /// <param name="userId">User's ID</param>
    /// <returns>
    /// IEnumerable(TfCommunicationGetChatRooms)
    /// </returns>
    IEnumerable<ChatRoomsPreviewDto> GetActiveRooms(int userId);

    /// <summary>
    /// Returns the conversation for the room passed as parameter
    /// </summary>
    /// <param name="roomId">Room ID</param>
    /// <returns>
    /// IEnumerable(TbCommunicationChatMessage)
    /// </returns>
    IEnumerable<ChatMessageDto> GetRoomConversation(long roomId);

    /// <summary>
    /// Marks as read by a user all messages in a chat room
    /// </summary>
    /// <param name="roomId">Room ID</param>
    /// <param name="userId">User ID that reads the messages</param>
    /// <returns>
    /// void
    /// </returns>
    void ReadAllMessages(long roomId, int userId);

    /// <summary>
    /// Inserts a new message to the database
    /// </summary>
    /// <param name="message">The message entity to be inserted</param>
    /// <returns>
    /// The inserted message
    /// </returns>
    ChatMessageDto AddMessage(ChatMessageDto message);

    /// <summary>
    /// Returns all members in a chat room
    /// </summary>
    /// <param name="roomId">Room ID</param>
    /// <returns>
    /// IEnumerable(ChatRoomMemberDto)
    /// </returns>
    List<ChatRoomMemberDto> GetRoomMembers(long roomId);

    /// <summary>
    /// Returns all members in a chat room
    /// </summary>
    /// <param name="roomName">Room's name</param>
    /// <param name="creationUser">Description of the user of creation</param>
    /// <returns>
    /// ID of the created room
    /// </returns>
    long CreateRoom(string roomName, string creationUser);

    /// <summary>
    /// Inserts a member into a chat room
    /// </summary>
    /// <param name="roomId">Room's ID</param>
    /// <param name="userId">User to be added</param>
    /// <param name="creationUser">Description of the user of creation</param>
    /// <returns>
    /// void
    /// </returns>
    void AddMember(long roomId, int userId, string creationUser);

    //TbCommunicationChatRoom StartChat(int hostUserId, int guestUserId);
    //bool ViewMessage(int userId, long messageId);
}