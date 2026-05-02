// 0x8009B0D4 (72B) TheSimsMainMenuState::~TheSimsMainMenuState(void)
// Variant K: dual vtable update at +0x18 + SDA singleton clear + deleting branch.

extern char vt_TheSimsMainMenuState_a[];
extern char vt_TheSimsMainMenuState_b[];
extern void* g_simsMenuStateInstance;

void __builtin_delete(void* p);

struct TheSimsMainMenuState {
    char pad_0_17[24];
    void* m_vt_at_18;
    void dtor(int flag);
};

void TheSimsMainMenuState::dtor(int flag) {
    m_vt_at_18 = vt_TheSimsMainMenuState_a;
    g_simsMenuStateInstance = 0;
    m_vt_at_18 = vt_TheSimsMainMenuState_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
