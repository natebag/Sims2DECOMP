/* CTGFileImpl::WriteFloat(float) at 0x8007D18C (64B) */

struct CTGFileImplVtable {
    char pad[0x50];
    short m_offset;
    int (*m_writeFunc)(void *, void *, int);
};

struct CTGFileImpl {
    CTGFileImplVtable *m_vtable;

    void WriteFloat(float val);
};

void CTGFileImpl::WriteFloat(float val) {
    CTGFileImplVtable *vt = m_vtable;
    float buf = val;
    ((int (*)(void *, void *, int))vt->m_writeFunc)((char *)this + vt->m_offset, &buf, 4);
}
