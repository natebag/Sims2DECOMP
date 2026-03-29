// 0x8021F548 (44 bytes) - InteractorModule::SocialModeInteractor::ChooseAction(Interaction *)
// if action: store action->id(+20) as short at this+96; else store -2; return 1

struct Interaction_CA {
    char pad[0x14];
    int m_id;
};

struct SocialModeInteractor_CA {
    char pad[0x60];
    short m_chosenActionID;

    int ChooseAction(Interaction_CA* action);
};

int SocialModeInteractor_CA::ChooseAction(Interaction_CA* action) {
    if (!action) {
        m_chosenActionID = -2;
        return 1;
    }
    int id = action->m_id;
    m_chosenActionID = id;
    return 1;
}
