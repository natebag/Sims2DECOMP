class Interaction;
class BString2;
class ERShader;

class ACTTarget {
public:
    void AddAction(int playerIndex, Interaction *interaction, BString2 &name, unsigned int flags, ERShader *shader, unsigned int id);
};

class H2DTarget {
public:
    char _pad[0xB4];
    ACTTarget *m_actTargets[2];

    void AddAction(int playerIndex, Interaction *interaction, BString2 &name, unsigned int flags, ERShader *shader, unsigned int id);
};

void H2DTarget::AddAction(int playerIndex, Interaction *interaction, BString2 &name, unsigned int flags, ERShader *shader, unsigned int id) {
    if ((unsigned int)playerIndex > 1) return;
    ACTTarget *act = m_actTargets[playerIndex];
    if (act != 0) {
        act->AddAction(playerIndex, interaction, name, flags, shader, id);
    }
}
