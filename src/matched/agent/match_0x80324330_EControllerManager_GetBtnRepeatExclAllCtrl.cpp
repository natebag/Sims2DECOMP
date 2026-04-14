// 0x80324330 EControllerManager::GetBtnRepeatExclAllCtrl (80B)
struct EController {};
typedef unsigned int (EController::*BtnFn)(EController*, unsigned int);
extern char g_btn_fn_GetBtnRepeatExclAllCtrl[];
struct EControllerManager {
    void GetBtnResultAllCtrl(BtnFn fn, bool a, bool b, unsigned int c, unsigned int* d, unsigned int e);
    void GetBtnRepeatExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetBtnRepeatExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    BtnFn fn = *(BtnFn*)g_btn_fn_GetBtnRepeatExclAllCtrl;
    GetBtnResultAllCtrl(fn, true, false, a, b, c);
}
