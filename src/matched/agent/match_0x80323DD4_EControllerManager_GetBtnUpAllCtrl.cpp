// 0x80323DD4 EControllerManager::GetBtnUpAllCtrl (80B)
struct EController {};
typedef unsigned int (EController::*BtnFn)(EController*, unsigned int);
extern char g_btn_fn_GetBtnUpAllCtrl[];
struct EControllerManager {
    void GetBtnResultAllCtrl(BtnFn fn, bool a, bool b, unsigned int c, unsigned int* d, unsigned int e);
    void GetBtnUpAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetBtnUpAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    BtnFn fn = *(BtnFn*)g_btn_fn_GetBtnUpAllCtrl;
    GetBtnResultAllCtrl(fn, false, false, a, b, c);
}
