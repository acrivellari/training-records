namespace TrainingRecords.Core.Dto;

public class ChatMessageDto
{
    public long MessageId { get; set; }
    public int UserId { get; set; }
    public string SenderName { get; set; }
    public long? RoomId { get; set; }
    public string MessageContent { get; set; }
    public DateTime MessageDate { get; set; }
}