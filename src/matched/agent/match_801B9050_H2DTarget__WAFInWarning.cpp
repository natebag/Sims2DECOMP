class MODTarget {
public:
    void SetWarning(int sidePanelId, bool a, bool b);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void WAFInWarning(int playerIndex, bool a, bool b);
};

void H2DTarget::WAFInWarning(int playerIndex, bool a, bool b) {
    MODTarget *mod = m_modTargets[playerIndex];
    if (mod != 0) {
        mod->SetWarning(4, a, b);
    }
}
