// FLAGS: -fno-schedule-insns
// 0x8032E884 ENgcEngine::IsResetting (8B)
// lwz r3,gIsResetting(r13)
extern int gIsResetting;
struct ENgcEngine { int IsResetting() const; };
int ENgcEngine::IsResetting() const { return gIsResetting; }
