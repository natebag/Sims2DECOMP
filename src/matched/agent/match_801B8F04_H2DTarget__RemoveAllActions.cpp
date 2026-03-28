class ACTTarget {
public:
    void RemoveAllActions(int playerIndex);
};

class H2DTarget {
public:
    char _pad[0xB4];
    ACTTarget *m_actTargets[2];

    void RemoveAllActions(int playerIndex);
};

void H2DTarget::RemoveAllActions(int playerIndex) {
    if ((unsigned int)playerIndex > 1) return;
    ACTTarget *act = m_actTargets[playerIndex];
    if (act != 0) {
        act->RemoveAllActions(playerIndex);
    }
}
