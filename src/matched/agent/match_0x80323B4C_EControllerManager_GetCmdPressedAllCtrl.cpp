// 0x80323B4C EControllerManager::GetCmdPressedAllCtrl (108B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn1_GetCmdPressedAllCtrl[];
extern char g_fn2_GetCmdPressedAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdPressedAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdPressedAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn1 = *(CmdFn*)g_fn1_GetCmdPressedAllCtrl;
    CmdFn fn2 = *(CmdFn*)g_fn2_GetCmdPressedAllCtrl;
    GetCmdResultAllCtrl(a, fn1, fn2, false, b, c);
}
