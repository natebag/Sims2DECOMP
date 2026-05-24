// FLAGS: -fno-schedule-insns
// 0x800EC07C GlobalConstantsClient::GetFileID (8B)
// lwz r3,gFileID(r13)
extern int gFileID;
struct GlobalConstantsClient { int GetFileID() const; };
int GlobalConstantsClient::GetFileID() const { return gFileID; }
