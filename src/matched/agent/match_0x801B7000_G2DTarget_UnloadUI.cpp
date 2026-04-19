// 0x801B7000 (64B) G2DTarget::UnloadUI(void)
// Guarded state-transition: if m_field_134 == 5 then bump to 6 and call
// UIScreenManager::UnloadUIScreen on the global UI-screen-manager pointer.
// g_uiMgrPtrHolder wraps the non-SDA pointer at 0x80475F10 via a fixed
// offset so the compiler emits lis+addi+lwz offset form (not SDA fused).

struct UIMgrHolder {
    char pad_000[0x5F10];
    void* g_uiMgr;
};
extern UIMgrHolder g_uiMgrPtrHolder;

void SomeHookFunc(void* obj, int code);

class G2DTarget {
public:
    char pad_000[0x134];
    int m_field_134;
    void UnloadUI(void);
};

void G2DTarget::UnloadUI(void) {
    if (m_field_134 != 5) return;
    m_field_134 = 6;
    SomeHookFunc(g_uiMgrPtrHolder.g_uiMgr, 47);
}
