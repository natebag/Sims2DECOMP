// FLAGS: -fno-schedule-insns
// 0x802E2928 EApp::GetAppName (12B)
// lis r3,HA(gAppName); addi r3,r3,LO(gAppName)
extern char gAppName[];
struct EApp { const char* GetAppName() const; };
const char* EApp::GetAppName() const { return gAppName; }
