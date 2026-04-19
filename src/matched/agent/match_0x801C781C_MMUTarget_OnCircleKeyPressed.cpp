// 0x801C781C (80B) MMUTarget::OnCircleKeyPressed(char*, char*)
// Double guard: if (m_08C != 0) return; if (g_flag == 0) return; then static + method call.
// Technique #49 3-layer hierarchy forces field offsets past the 0x80 vtable slot.

struct MMUTargetBase_C { char pad[128]; };
struct MMUTargetMid_C : public MMUTargetBase_C {
    virtual void f0_filler() = 0;
    virtual void f1_filler() = 0;
};

extern char g_mmuFlag[16];

class MMUTarget : public MMUTargetMid_C {
public:
    char pad_084[8];
    int m_field_08C;

    static void ChangeScreenMode(void);
    void UpdateText(void);
    void OnCircleKeyPressed(char* a, char* b);
};

void MMUTarget::OnCircleKeyPressed(char*, char*) {
    if (m_field_08C != 0) return;
    if (*(int*)g_mmuFlag == 0) return;
    MMUTarget::ChangeScreenMode();
    this->UpdateText();
}
