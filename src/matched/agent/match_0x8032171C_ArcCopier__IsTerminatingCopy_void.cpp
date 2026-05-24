// FLAGS: -fno-schedule-insns
// 0x8032171C ArcCopier::IsTerminatingCopy (8B)
// lwz r3,gIsTerminatingCopy(r13)
extern int gIsTerminatingCopy;
struct ArcCopier { int IsTerminatingCopy() const; };
int ArcCopier::IsTerminatingCopy() const { return gIsTerminatingCopy; }
