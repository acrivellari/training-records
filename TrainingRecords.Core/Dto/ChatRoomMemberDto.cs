namespace TrainingRecords.Core.Dto
{
    public class ChatRoomMemberDto
    {
        public long MemberId { get; set; }
        public long RoomId { get; set; }
        public int UserId { get; set; }
        public string ConnectionId { get; set; }
        public bool IsDeleted { get; set; }
        public string CreationUser { get; set; }
        public DateTime? CreationDate { get; set; }
        public string DeletionUser { get; set; }
        public DateTime? DeletionDate { get; set; }
    }
}