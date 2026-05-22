// 0x801A4018 BBHTarget::SetBBHMode(int) (88B)

class UIReflow {
public:
    char data[24];
    UIReflow();
    ~UIReflow();
    void ResetFontSizeOverride(char* name, unsigned int sz, int p3);
};

extern char g_str_BBH_mode[16];

class BBHTarget {
public:
    char pad[0xA0];
    int m_A0;
    void SetBBHMode(int mode);
};

void BBHTarget::SetBBHMode(int mode) {
    if (m_A0 == mode) return;
    m_A0 = mode;
    UIReflow reflow;
    reflow.ResetFontSizeOverride(g_str_BBH_mode, 16, 0);
}
