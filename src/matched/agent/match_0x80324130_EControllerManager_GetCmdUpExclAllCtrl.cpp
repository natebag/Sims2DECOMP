// 0x80324130 EControllerManager::GetCmdUpExclAllCtrl (84B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn_GetCmdUpExclAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdUpExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdUpExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn = *(CmdFn*)g_fn_GetCmdUpExclAllCtrl;
    GetCmdResultAllCtrl(a, fn, fn, true, b, c);
}
