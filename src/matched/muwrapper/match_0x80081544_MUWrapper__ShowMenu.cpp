// 0x80081544 (72B) MUWrapper::ShowMenu(void)
// Lazy-init guard: if m_field196==0, call MenuFunc(self, kShowStr), set flag=1.
// Single callee-saved r31=self across function call.

extern char kMUShowMenuStr[16];
void MUWrapper_MenuFunc(void* self, const char* name);

struct MUWrapper_SM {
    char _pad[196];
    int m_isMenuShown;
    void ShowMenu();
};

void MUWrapper_SM::ShowMenu() {
    if (m_isMenuShown == 0) {
        MUWrapper_MenuFunc(this, kMUShowMenuStr);
        m_isMenuShown = 1;
    }
}
