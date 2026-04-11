/* CTGFileImpl::WriteInteger(int) at 0x8007D114 (64B) */

struct CTGFileImplVtable {
    char pad[0x50];
    short m_offset;
    int (*m_writeFunc)(void *, void *, int);
};

struct CTGFileImpl {
    CTGFileImplVtable *m_vtable;

    void WriteInteger(int val);
};

void CTGFileImpl::WriteInteger(int val) {
    int buf = val;
    CTGFileImplVtable *vt = m_vtable;
    ((int (*)(void *, void *, int))vt->m_writeFunc)((char *)this + vt->m_offset, &buf, 4);
}
