/* MODTarget::DisplayFastForward(void) at 0x801CA9B0 (84B) */

extern char s_ffwdStr[];

struct UIReflow {
    void ResetVisibility(char*, int, int);
};

struct MODTarget {
    char pad_000[0x94];
    int m_field94;
    char pad_098[0xC8 - 0x98];
    UIReflow m_reflow;
    char pad_CXX[0xE4 - 0xC8 - sizeof(UIReflow)];
    int m_fieldE4;

    void DisplayFastForward();
};

void MODTarget::DisplayFastForward() {
    if (m_field94 == 0) {
        m_reflow.ResetVisibility(s_ffwdStr, 1, 0);
        m_fieldE4 = 6;
    }
}
