// FLAGS: -fno-schedule-insns
// 0x800BCA10 IconGroupImpl::IconGroupImpl(void) (36B)

extern int IconGroupImpl_vtable[];

struct IconGroupImpl {
    int *m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    IconGroupImpl();
};

IconGroupImpl::IconGroupImpl() {
    m_vtable = (int *)IconGroupImpl_vtable;
    m_fieldC = 0;
    m_field8 = 0;
    m_field4 = 0;
}
