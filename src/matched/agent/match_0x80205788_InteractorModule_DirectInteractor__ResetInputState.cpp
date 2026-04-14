// 0x80205788 InteractorModule::DirectInteractor::ResetInputState(void) (52B)
struct DirectInteractor {
    char pad[48];
    int m_inputState;
};

extern void Interactor__ResetInputStateBase(DirectInteractor* self);

void DirectInteractor__ResetInputState(DirectInteractor* self) {
    Interactor__ResetInputStateBase(self);
    self->m_inputState = 0;
}
