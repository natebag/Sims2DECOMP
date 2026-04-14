// 0x803241F0 EControllerManager::GetBtnDownExclAllCtrl (80B)
struct EController {};
typedef unsigned int (EController::*BtnFn)(EController*, unsigned int);
extern char g_btn_fn_GetBtnDownExclAllCtrl[];
struct EControllerManager {
    void GetBtnResultAllCtrl(BtnFn fn, bool a, bool b, unsigned int c, unsigned int* d, unsigned int e);
    void GetBtnDownExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetBtnDownExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    BtnFn fn = *(BtnFn*)g_btn_fn_GetBtnDownExclAllCtrl;
    GetBtnResultAllCtrl(fn, true, false, a, b, c);
}
