/* cSoundModeManager::Shutdown(void) at 0x800B0364 (56B) */

struct SndShutVtable {
    char pad[0x48];
    short m_vbaseOff;
    int (*m_shutdownFunc)(void *);
};

struct SndShutObj {
    SndShutVtable *m_vtable;
};

extern SndShutObj *g_soundModeMgr;

void cSoundModeManager_Shutdown(void) {
    SndShutVtable *vt = g_soundModeMgr->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_shutdownFunc;
    fn((char *)g_soundModeMgr + off);
}
