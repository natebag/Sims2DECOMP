// 0x80324470 EControllerManager::GetBtnUpAnyExclAllCtrl (80B)
struct EController {};
typedef unsigned int (EController::*BtnFn)(EController*, unsigned int);
extern char g_btn_fn_GetBtnUpAnyExclAllCtrl[];
struct EControllerManager {
    void GetBtnResultAllCtrl(BtnFn fn, bool a, bool b, unsigned int c, unsigned int* d, unsigned int e);
    void GetBtnUpAnyExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetBtnUpAnyExclAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    BtnFn fn = *(BtnFn*)g_btn_fn_GetBtnUpAnyExclAllCtrl;
    GetBtnResultAllCtrl(fn, true, true, a, b, c);
}
