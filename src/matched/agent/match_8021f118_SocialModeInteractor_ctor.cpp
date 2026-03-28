extern int SocialModeInteractor_vtable[];

void Interactor_BaseInit();

struct SocialModeInteractor {
    char pad_base[0x5C];
    int *m_vtable_5C;
    short m_field60;
    char pad_62[0x0A];
    int m_field6C;

    SocialModeInteractor();
};

SocialModeInteractor::SocialModeInteractor() {
    Interactor_BaseInit();
    m_vtable_5C = SocialModeInteractor_vtable;
    m_field60 = -1;
    m_field6C = -1;
}
