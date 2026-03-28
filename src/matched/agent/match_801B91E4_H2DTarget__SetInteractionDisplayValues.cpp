class INTTarget {
public:
    void SetInteractionDisplayValues(unsigned int, unsigned int);
};

class H2DTarget {
public:
    char _pad[0xBC];
    INTTarget *m_intTargets[2];

    void SetInteractionDisplayValues(int playerIndex, unsigned int a, unsigned int b);
};

void H2DTarget::SetInteractionDisplayValues(int playerIndex, unsigned int a, unsigned int b) {
    INTTarget *tgt = m_intTargets[playerIndex];
    if (tgt != 0) {
        tgt->SetInteractionDisplayValues(a, b);
    }
}
