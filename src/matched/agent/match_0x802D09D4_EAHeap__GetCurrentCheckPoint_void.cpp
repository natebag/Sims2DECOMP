// FLAGS: -fno-schedule-insns
// 0x802D09D4 EAHeap::GetCurrentCheckPoint (8B)
// lwz r3,gCheckPoint(r13)
extern int gCheckPoint;
struct EAHeap { int GetCurrentCheckPoint() const; };
int EAHeap::GetCurrentCheckPoint() const { return gCheckPoint; }
