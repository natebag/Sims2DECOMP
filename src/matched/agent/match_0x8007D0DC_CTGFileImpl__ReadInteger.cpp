/* CTGFileImpl::ReadInteger(int *) at 0x8007D0DC (56B) */

struct CTGReadIntVtable {
    char pad[0x48];
    short m_vbaseOff;
    int (*m_readFunc)(void *, void *, int);
};

struct CTGFileImplRI {
    CTGReadIntVtable *m_vtable;

    int ReadInteger(int *out);
};

int CTGFileImplRI::ReadInteger(int *out) {
    CTGReadIntVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, void *, int) = vt->m_readFunc;
    return fn((char *)this + off, out, 4);
}
