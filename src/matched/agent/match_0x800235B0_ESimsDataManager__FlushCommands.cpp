/* ESimsDataManager::FlushCommands(void) at 0x800235B0 (56B) */

struct FlushVtable {
    char pad[0x38];
    short m_vbaseOff;
    int (*m_flushFunc)(void *);
};

struct FlushObj {
    FlushVtable *m_vtable;
};

extern FlushObj *g_simsDataMgr;

void ESimsDataManager_FlushCommands(void) {
    FlushVtable *vt = g_simsDataMgr->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_flushFunc;
    fn((char *)g_simsDataMgr + off);
}
