// 0x80323CE4 EControllerManager::GetBtnDownAllCtrl (80B)
struct EController {};
typedef unsigned int (EController::*BtnFn)(EController*, unsigned int);
extern char g_btn_fn_GetBtnDownAllCtrl[];
struct EControllerManager {
    void GetBtnResultAllCtrl(BtnFn fn, bool a, bool b, unsigned int c, unsigned int* d, unsigned int e);
    void GetBtnDownAllCtrl(unsigned int a, unsigned int* b, unsigned int c);
};
void EControllerManager::GetBtnDownAllCtrl(unsigned int a, unsigned int* b, unsigned int c) {
    BtnFn fn = *(BtnFn*)g_btn_fn_GetBtnDownAllCtrl;
    GetBtnResultAllCtrl(fn, false, false, a, b, c);
}
