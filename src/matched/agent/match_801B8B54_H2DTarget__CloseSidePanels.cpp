class MOTTarget {
public:
    void HideMotives(void);
};

class SKLTarget {
public:
    void HideSkills(void);
};

class WAFTarget {
public:
    void HideWantsAndFears(void);
};

class H2DTarget {
public:
    char _pad0[0x9C];
    MOTTarget *m_motTargets[2];
    SKLTarget *m_sklTargets[2];
    WAFTarget *m_wafTargets[2];

    void CloseSidePanels(int playerIndex);
};

void H2DTarget::CloseSidePanels(int playerIndex) {
    m_motTargets[playerIndex]->HideMotives();
    m_sklTargets[playerIndex]->HideSkills();
    m_wafTargets[playerIndex]->HideWantsAndFears();
}
