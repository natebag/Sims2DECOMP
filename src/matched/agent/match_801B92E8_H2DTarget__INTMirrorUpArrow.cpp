class INTTarget {
public:
    void MirrorUpArrow(bool);
};

class H2DTarget {
public:
    char _pad[0xBC];
    INTTarget *m_intTargets[2];

    void INTMirrorUpArrow(int playerIndex, bool mirror);
};

void H2DTarget::INTMirrorUpArrow(int playerIndex, bool mirror) {
    m_intTargets[playerIndex]->MirrorUpArrow(mirror);
}
