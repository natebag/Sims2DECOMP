void DI_BaseReset();

struct DirectInteractor_ResetInputState_S {
    char pad[0x30];
    int m_commandId;

    void ResetInputState();
};

void DirectInteractor_ResetInputState_S::ResetInputState() {
    DI_BaseReset();
    m_commandId = 0;
}
