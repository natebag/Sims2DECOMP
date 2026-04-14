// 0x8021E5D8 InteractorModule::SimInteractor::ResetInputState(void) (52B)
struct SimInteractor {
    char pad[48];
    int m_field48;
    char pad2[340];
    int m_field392;
};

extern void Interactor__ResetInputStateBase(SimInteractor* self);

void SimInteractor__ResetInputState(SimInteractor* self) {
    Interactor__ResetInputStateBase(self);
    self->m_field48 = 0;
    self->m_field392 = 0;
}
