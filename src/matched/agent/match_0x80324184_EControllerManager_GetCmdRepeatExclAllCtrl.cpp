// 0x80324184 EControllerManager::GetCmdRepeatExclAllCtrl (108B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn1_GetCmdRepeatExclAllCtrl[];
extern char g_fn2_GetCmdRepeatExclAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdRepeatExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdRepeatExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn1 = *(CmdFn*)g_fn1_GetCmdRepeatExclAllCtrl;
    CmdFn fn2 = *(CmdFn*)g_fn2_GetCmdRepeatExclAllCtrl;
    GetCmdResultAllCtrl(a, fn1, fn2, true, b, c);
}
