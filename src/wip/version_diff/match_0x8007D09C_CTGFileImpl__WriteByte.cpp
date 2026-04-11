/* CTGFileImpl::WriteByte(unsigned char) at 0x8007D09C (64B) */

struct CTGFileImplVtable {
    char pad[0x50];
    short m_offset;
    int (*m_writeFunc)(void *, void *, int);
};

struct CTGFileImpl {
    CTGFileImplVtable *m_vtable;

    void WriteByte(unsigned char val);
};

void CTGFileImpl::WriteByte(unsigned char val) {
    unsigned char buf = val;
    CTGFileImplVtable *vt = m_vtable;
    ((int (*)(void *, void *, int))vt->m_writeFunc)((char *)this + vt->m_offset, &buf, 1);
}
