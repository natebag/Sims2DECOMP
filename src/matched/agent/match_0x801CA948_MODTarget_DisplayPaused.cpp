// 0x801CA948 (104B) MODTarget::DisplayPaused(void) — stack-local UIReflow RAII

extern char s_MOD_pause_swf[];

struct UIReflow {
    char pad[24];
    UIReflow();
    ~UIReflow();
    void ResetVisibility(char*, int, int);
};

struct MODTarget {
    char pad_000[0x94];
    int m_field94;
    char pad_098[0xE0 - 0x98];
    int m_fieldE0;
    void DisplayPaused();
};

void MODTarget::DisplayPaused() {
    if (m_field94 == 0) {
        UIReflow reflow;
        reflow.ResetVisibility(s_MOD_pause_swf, 1, 0);
        m_fieldE0 = 6;
    }
}
