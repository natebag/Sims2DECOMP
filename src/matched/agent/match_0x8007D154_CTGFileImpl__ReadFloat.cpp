/* CTGFileImpl::ReadFloat(float *) at 0x8007D154 (56B) */

struct CTGReadFltVtable {
    char pad[0x48];
    short m_vbaseOff;
    int (*m_readFunc)(void *, void *, int);
};

struct CTGFileImplRF {
    CTGReadFltVtable *m_vtable;

    int ReadFloat(float *out);
};

int CTGFileImplRF::ReadFloat(float *out) {
    CTGReadFltVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, void *, int) = vt->m_readFunc;
    return fn((char *)this + off, out, 4);
}
