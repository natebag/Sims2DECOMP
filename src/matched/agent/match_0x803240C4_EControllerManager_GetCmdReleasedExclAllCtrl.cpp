// 0x803240C4 EControllerManager::GetCmdReleasedExclAllCtrl (108B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn1_GetCmdReleasedExclAllCtrl[];
extern char g_fn2_GetCmdReleasedExclAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdReleasedExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdReleasedExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn1 = *(CmdFn*)g_fn1_GetCmdReleasedExclAllCtrl;
    CmdFn fn2 = *(CmdFn*)g_fn2_GetCmdReleasedExclAllCtrl;
    GetCmdResultAllCtrl(a, fn1, fn2, true, b, c);
}
