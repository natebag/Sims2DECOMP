// 0x800B039C cSoundModeManager::Pause(void) (100B)
// MI-vcall pattern: struct vtable with 8-byte entries {short delta, int* fn}
// Two virtual calls on g_soundModeMgr global:
//   slot 10 (off=80,fn=84): PauseMusic (no extra args)
//   slot 5  (off=40,fn=44): SetActive(1) (with int arg)
// FLAGS: -fno-schedule-insns
// ASMPROC_gpr_relabel: swap="9:11"
// ASMPROC_replace_insn: match="lwz 10,84(9)" replacement="lwz 0,84(9)"
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

struct cSoundModeManager {
    int m_mode;
};

extern "C" void cSoundModeManager_Pause(cSoundModeManager *self) {
    if (self->m_mode != 3) {
        SndMgrVtable *vt = g_soundModeMgr->m_vtable;
        int (*fn)(void*) = vt->pauseFunc;
        short off = vt->pauseOff;
        fn((char*)g_soundModeMgr + off);
        vt = g_soundModeMgr->m_vtable;
        short off2 = vt->setActiveOff;
        int (*fn2)(void*, int) = vt->setActiveFunc;
        fn2((char*)g_soundModeMgr + off2, 1);
    }
}
