// 0x801B8C98 (116B) H2DTarget::ACTCancelModeExited(int)
class AptViewer {
public:
    void PopAptButtonFilter(int, unsigned int);
};

class MODTarget {
public:
    enum eSidePanelIcon { kIcon4 = 4 };
    void SetDpadIcons(eSidePanelIcon);
};

extern char g_AptViewer_mem[16];

struct H2DTarget {
    char pad[136];
    MODTarget* m_mods[2];       // 136 (0x88)
    char pad2[260 - 136 - 8];
    int m_active[2];            // 260 (0x104)
    int m_filters[2];           // 268 (0x10C)
    void ACTCancelModeExited(int idx);
};

void H2DTarget::ACTCancelModeExited(int idx) {
    if (m_active[idx] != 0) {
        m_active[idx] = 0;
        unsigned int filter = m_filters[idx];
        if (filter != 0) {
            AptViewer* v = *((AptViewer**)g_AptViewer_mem);
            v->PopAptButtonFilter(idx, filter);
            m_filters[idx] = 0;
            m_mods[idx]->SetDpadIcons((MODTarget::eSidePanelIcon)4);
        }
    }
}
