// 0x80323AF8 EControllerManager::GetCmdDownAllCtrl (84B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn_GetCmdDownAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdDownAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdDownAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn = *(CmdFn*)g_fn_GetCmdDownAllCtrl;
    GetCmdResultAllCtrl(a, fn, fn, false, b, c);
}
