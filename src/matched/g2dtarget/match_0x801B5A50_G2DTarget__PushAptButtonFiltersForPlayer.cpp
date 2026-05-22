// 0x801B5A50 (92B) G2DTarget::PushAptButtonFiltersForPlayer(int)

extern char g_someFlag_0x80475C70[16];

extern "C" void* pushAptButtonFilterALL__12UIObjectBaseFiPc(int, char*);

class G2DTarget {
public:
    char m_pad[124];
    char* m_7C_buttonName;
    char m_padFiller[288 - 128];
    void* m_120_filters[8];
    void PushAptButtonFiltersForPlayer(int player);
};

void G2DTarget::PushAptButtonFiltersForPlayer(int player) {
    if (player == 1) {
        if (*(int*)g_someFlag_0x80475C70 == 0) return;
    }
    void* filter = pushAptButtonFilterALL__12UIObjectBaseFiPc(player, m_7C_buttonName);
    m_120_filters[player] = filter;
}
