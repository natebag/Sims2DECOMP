/* CheckForFileDescriptorLeaks(char *, int) at 0x80074DE0 (64B) */

struct FileCheckVtable {
    char pad[0x30];
    short m_vbaseOff;
    int (*m_checkFunc)(void *, char *, int);
};

struct FileCheckObj {
    FileCheckVtable *m_vtable;
};

extern FileCheckObj *g_fileCheckObj;

void CheckForFileDescriptorLeaks(char *name, int count) {
    FileCheckVtable *vt = g_fileCheckObj->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, char *, int) = vt->m_checkFunc;
    fn((char *)g_fileCheckObj + off, name, count);
}
