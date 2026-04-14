// 0x8020955C InteractorModule::Interactor::EitherStickCentered(void) (40B)
struct Interactor {
    char pad[68];
    int m_stick0;
    int m_stick1;
};

int Interactor__EitherStickCentered(Interactor* self) {
    int r = 0;
    if (self->m_stick0 != 0 || self->m_stick1 != 0) r = 1;
    return r;
}
