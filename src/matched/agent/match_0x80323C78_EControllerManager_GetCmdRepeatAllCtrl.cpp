// 0x80323C78 EControllerManager::GetCmdRepeatAllCtrl (108B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn1_GetCmdRepeatAllCtrl[];
extern char g_fn2_GetCmdRepeatAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdRepeatAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdRepeatAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn1 = *(CmdFn*)g_fn1_GetCmdRepeatAllCtrl;
    CmdFn fn2 = *(CmdFn*)g_fn2_GetCmdRepeatAllCtrl;
    GetCmdResultAllCtrl(a, fn1, fn2, false, b, c);
}
