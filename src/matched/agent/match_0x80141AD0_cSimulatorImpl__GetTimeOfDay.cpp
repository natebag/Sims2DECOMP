/* cSimulatorImpl::GetTimeOfDay(void) at 0x80141AD0 (56B) */

struct SimTimeVtable {
    char pad[0x30];
    short m_vbaseOff;
    int (*m_getTimeFunc)(void *, int);
};

struct cSimulatorImpl_GT {
    SimTimeVtable *m_vtable;

    int GetTimeOfDay(void);
};

int cSimulatorImpl_GT::GetTimeOfDay(void) {
    SimTimeVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int) = vt->m_getTimeFunc;
    return fn((char *)this + off, 4);
}
