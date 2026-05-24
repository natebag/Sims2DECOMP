// FLAGS: -fno-schedule-insns
// 0x802E291C EApp::GetBuildVersion (12B)
// lis r3,HA(gBuildVersion); addi r3,r3,LO(gBuildVersion)
extern char gBuildVersion[];
struct EApp { const char* GetBuildVersion() const; };
const char* EApp::GetBuildVersion() const { return gBuildVersion; }
