// 0x80324058 EControllerManager::GetCmdPressedExclAllCtrl (108B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn1_GetCmdPressedExclAllCtrl[];
extern char g_fn2_GetCmdPressedExclAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdPressedExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdPressedExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn1 = *(CmdFn*)g_fn1_GetCmdPressedExclAllCtrl;
    CmdFn fn2 = *(CmdFn*)g_fn2_GetCmdPressedExclAllCtrl;
    GetCmdResultAllCtrl(a, fn1, fn2, true, b, c);
}
