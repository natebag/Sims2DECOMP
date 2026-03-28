class CSMTarget {
public:
    void SetIconDisable(bool);
};

class H2DTarget {
public:
    char _pad[0x90];
    CSMTarget *m_csmTargets[2];

    void CSIMSetIconDisable(int playerIndex, bool disable);
};

void H2DTarget::CSIMSetIconDisable(int playerIndex, bool disable) {
    m_csmTargets[playerIndex]->SetIconDisable(disable);
}
