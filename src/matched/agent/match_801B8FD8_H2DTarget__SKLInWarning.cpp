class MODTarget {
public:
    void SetWarning(int sidePanelId, bool a, bool b);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void SKLInWarning(int playerIndex, bool active);
};

void H2DTarget::SKLInWarning(int playerIndex, bool active) {
    MODTarget *mod = m_modTargets[playerIndex];
    if (mod != 0) {
        mod->SetWarning(2, active, 1);
    }
}
