class Neighbor;

class WAFTarget {
public:
    enum eWAFIconAnim {};
    void NewWantsAndFearsIcon(int id, unsigned int a, unsigned int b, eWAFIconAnim anim, Neighbor *neighbor);
};

class H2DTarget {
public:
    char _pad[0xAC];
    WAFTarget *m_wafTargets[2];

    void NewWantFearIcon(int playerIndex, int id, unsigned int a, unsigned int b, WAFTarget::eWAFIconAnim anim, Neighbor *neighbor);
};

void H2DTarget::NewWantFearIcon(int playerIndex, int id, unsigned int a, unsigned int b, WAFTarget::eWAFIconAnim anim, Neighbor *neighbor) {
    WAFTarget *waf = m_wafTargets[playerIndex];
    if (waf != 0) {
        waf->NewWantsAndFearsIcon(id, a, b, anim, neighbor);
    }
}
