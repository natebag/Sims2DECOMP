class Interaction;

class ACTTarget {
public:
    void RemoveAction(int playerIndex, Interaction *interaction);
};

class H2DTarget {
public:
    char _pad[0xB4];
    ACTTarget *m_actTargets[2];

    void RemoveAction(int playerIndex, Interaction *interaction);
};

void H2DTarget::RemoveAction(int playerIndex, Interaction *interaction) {
    if ((unsigned int)playerIndex > 1) return;
    ACTTarget *act = m_actTargets[playerIndex];
    if (act != 0) {
        act->RemoveAction(playerIndex, interaction);
    }
}
