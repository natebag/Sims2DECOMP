// 0x80324004 EControllerManager::GetCmdDownExclAllCtrl (84B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn_GetCmdDownExclAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdDownExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdDownExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn = *(CmdFn*)g_fn_GetCmdDownExclAllCtrl;
    GetCmdResultAllCtrl(a, fn, fn, true, b, c);
}
