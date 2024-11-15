namespace TrainingRecords.Core.Dto;

public class ChatRoomsPreviewDto
{
    public long RoomId { get; set; }
    public string Name { get; set; }
    public int? Companion { get; set; }
    public string CompanionPicture { get; set; }
    public int UnreadMessages { get; set; }
    public string LastMessageContent { get; set; }
    public DateTime? LastMessageDate { get; set; }
}