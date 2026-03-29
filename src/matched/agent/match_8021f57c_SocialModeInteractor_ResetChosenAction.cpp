struct SocialModeInteractor_RCA {
    char pad[0x60];
    short m_chosenAction;

    void ResetChosenAction();
};

void SocialModeInteractor_RCA::ResetChosenAction() {
    m_chosenAction = -1;
}
