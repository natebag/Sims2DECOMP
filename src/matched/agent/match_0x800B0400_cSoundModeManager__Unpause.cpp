// 0x800B0400 cSoundModeManager::Unpause(void) (88B)
// Same MI-vcall pattern as Pause; no mode check; first call is slot 11 (UnpauseMusic, off=88,fn=92)
// FLAGS: -fno-schedule-insns
// ASMPROC_gpr_relabel: swap="9:11"
// ASMPROC_replace_insn: match="lwz 10,92(9)" replacement="lwz 0,92(9)"
// ASMPROC_replace_insn: match="mtlr 10" replacement="mtlr 0"

struct SndMgrVtable {
    char _pad0[40];
    short setActiveOff; short _p1;
    int (*setActiveFunc)(void*, int);
    char _pad2[32];
    short pauseOff; short _p3;
    int (*pauseFunc)(void*);
    short unpauseOff; short _p4;
    int (*unpauseFunc)(void*);
};

struct SndMgrObj {
    SndMgrVtable *m_vtable;
};

extern SndMgrObj *g_soundModeMgr;

extern "C" void cSoundModeManager_Unpause(void) {
    SndMgrVtable *vt = g_soundModeMgr->m_vtable;
    int (*fn)(void*) = vt->unpauseFunc;
    short off = vt->unpauseOff;
    fn((char*)g_soundModeMgr + off);
    vt = g_soundModeMgr->m_vtable;
    short off2 = vt->setActiveOff;
    int (*fn2)(void*, int) = vt->setActiveFunc;
    fn2((char*)g_soundModeMgr + off2, 1);
}
