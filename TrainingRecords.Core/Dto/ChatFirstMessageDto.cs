namespace TrainingRecords.Core.Dto;

public class ChatFirstMessageDto
{
    public long MessageId { get; set; }
    public int UserId { get; set; }
    public long? RoomId { get; set; }
    public string MessageContent { get; set; }
    public DateTime MessageDate { get; set; }
    public List<int> UsersInRoom { get; set; }
}