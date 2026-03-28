class MODTarget {
public:
    void SetDpadIcons(int icon);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void CSIMActive(int playerIndex, bool active);
};

void H2DTarget::CSIMActive(int playerIndex, bool active) {
    MODTarget *mod = m_modTargets[playerIndex];
    if (mod != 0) {
        if (active) {
            mod->SetDpadIcons(1);
        } else {
            mod->SetDpadIcons(4);
        }
    }
}
