/* CTGFileImpl::ReadByte(unsigned char *) at 0x8007D064 (56B) */

struct CTGReadVtable {
    char pad[0x48];
    short m_vbaseOff;
    int (*m_readFunc)(void *, void *, int);
};

struct CTGFileImplR {
    CTGReadVtable *m_vtable;

    int ReadByte(unsigned char *out);
};

int CTGFileImplR::ReadByte(unsigned char *out) {
    CTGReadVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, void *, int) = vt->m_readFunc;
    return fn((char *)this + off, out, 1);
}
