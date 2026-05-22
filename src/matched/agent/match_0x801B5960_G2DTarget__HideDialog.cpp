// FLAGS: -fno-schedule-insns
// 0x801B5960 G2DTarget::HideDialog() (96B)

extern char g_G2D_hide_err_str[16];  // at 0x803F0CFC

extern "C" int G2DDummyPrintf(char* fmt, ...);

class G2DTarget {
public:
    char pad[0xC4];
    int m_C4;
    char padC8[0x48];
    int m_110;
    int m_114;
    int m_118;
    char pad11C[0x18];
    int m_134;
    void HideDialog();
};

void G2DTarget::HideDialog() {
    if (m_134 != 3) {
        G2DDummyPrintf(g_G2D_hide_err_str);
        return;
    }
    if (m_C4 == 0) {
        m_118 = 0;
    }
    m_134 = 4;
    m_114 = 0;
    m_110 = 0;
}
