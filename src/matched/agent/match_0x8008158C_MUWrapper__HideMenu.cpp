// 0x8008158C (72B) MUWrapper::HideMenu(void)
// Symmetric inverse of ShowMenu: if m_field196!=0, call MenuFunc(self, kHideStr), clear flag.
// Single callee-saved r31=self across function call.

extern char kMUHideMenuStr[16];
void MUWrapper_MenuFunc(void* self, const char* name);

struct MUWrapper_HM {
    char _pad[196];
    int m_isMenuShown;
    void HideMenu();
};

void MUWrapper_HM::HideMenu() {
    if (m_isMenuShown != 0) {
        MUWrapper_MenuFunc(this, kMUHideMenuStr);
        m_isMenuShown = 0;
    }
}
