class INTTarget {
public:
    void TriggerInteractionAnimation(unsigned int, unsigned int, unsigned int);
};

class H2DTarget {
public:
    char _pad[0xBC];
    INTTarget *m_intTargets[2];

    void TriggerInteractionAnimation(int playerIndex, unsigned int a, unsigned int b, unsigned int c);
};

void H2DTarget::TriggerInteractionAnimation(int playerIndex, unsigned int a, unsigned int b, unsigned int c) {
    INTTarget *tgt = m_intTargets[playerIndex];
    if (tgt != 0) {
        tgt->TriggerInteractionAnimation(a, b, c);
    }
}
