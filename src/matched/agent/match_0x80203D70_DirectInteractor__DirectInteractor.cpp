/* InteractorModule::DirectInteractor::DirectInteractor(void) at 0x80203D70 (96B) */
/* [VERSION_DIFF] v3.93 schedules lfs before lis; DOL has lis first */
/* Also SDA float load instruction order differs from v1.76 */

float gDI_initSpeed = 0.0f;
extern int DI_VT[];

void Interactor_ctor(void);

struct DI_CtorS {
    char _pad0[0x5C];
    int *m_vtable;
    char _pad60[0x04];
    int m_field64;
    char _pad68[0x08];
    int m_field70;
    float m_field74;
    int m_field78;
    int m_field7C;
    int m_field80;

    DI_CtorS *ctor(void);
};

DI_CtorS *DI_CtorS::ctor(void) {
    Interactor_ctor();
    m_vtable = DI_VT;
    m_field64 = 1;
    m_field74 = gDI_initSpeed;
    m_field80 = 0;
    m_field70 = 0;
    m_field78 = 0;
    m_field7C = 0;
    return this;
}
