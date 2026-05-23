extern int SMI_VT[];

void Interactor_ctor(void);

struct SMI_CtorS {
    char _pad0[0x5C];
    int *m_vtable;
    short m_field60;
    char _pad62[0x0A];
    int m_field6C;

    SMI_CtorS *ctor(void);
};

SMI_CtorS *SMI_CtorS::ctor(void) {
    Interactor_ctor();
    m_vtable = SMI_VT;
    m_field60 = -1;
    m_field6C = -1;
    return this;
}
