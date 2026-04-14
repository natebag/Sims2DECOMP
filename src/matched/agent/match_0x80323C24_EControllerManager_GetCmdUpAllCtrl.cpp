// 0x80323C24 EControllerManager::GetCmdUpAllCtrl (84B)
struct EController {};
typedef unsigned int (EController::*CmdFn)(EController*, unsigned int);
extern char g_fn_GetCmdUpAllCtrl[];
struct EControllerManager {
    void GetCmdResultAllCtrl(unsigned int a, CmdFn fn1, CmdFn fn2, bool b, unsigned int* c, unsigned int d);
    void GetCmdUpAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetCmdUpAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    CmdFn fn = *(CmdFn*)g_fn_GetCmdUpAllCtrl;
    GetCmdResultAllCtrl(a, fn, fn, false, b, c);
}
