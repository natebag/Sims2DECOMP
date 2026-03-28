class MODTarget {
public:
    void SetWarning(int sidePanelId, bool a, bool b);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void MOTInWarning(int playerIndex, bool active);
};

void H2DTarget::MOTInWarning(int playerIndex, bool active) {
    MODTarget *mod = m_modTargets[playerIndex];
    if (mod != 0) {
        mod->SetWarning(3, active, 0);
    }
}
