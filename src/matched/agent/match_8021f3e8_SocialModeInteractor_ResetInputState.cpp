void SMI_BaseReset();

struct SocialModeInteractor_ResetInputState_S {
    char pad[0x30];
    int m_commandId;

    void ResetInputState();
};

void SocialModeInteractor_ResetInputState_S::ResetInputState() {
    SMI_BaseReset();
    m_commandId = 0;
}
