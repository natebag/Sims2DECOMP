// 0x80014C14 BGExec_LoadHouse (88b)
// FLAGS: -fno-elide-constructors -fno-peephole

struct BGLoadVt {
    char pad[0x40];
    short m_off;
    char _p[2];
    int (*m_fn)(void *, void *, int, int);
};

struct BGLoadMgr {
    BGLoadVt *m_vt;
};

struct EGlobalSub {
    char pad_00[0x54];
    int m_field_54;
};

struct EGlobal_LH {
    char pad_000[0xC8];
    EGlobalSub *m_field_C8;
    char pad_0CC[0x8C];
    int m_field_158;
};

extern BGLoadMgr *g_bgExecObj;
extern void *g_houseNameArg;
extern int g_bgLoadFlag;
extern EGlobal_LH _globals;

void BGExec_LoadHouse(void) {
    BGLoadMgr *mgr = g_bgExecObj;
    BGLoadVt *vt = mgr->m_vt;
    vt->m_fn(
        (char *)mgr + vt->m_off,
        g_houseNameArg,
        _globals.m_field_C8->m_field_54,
        _globals.m_field_158
    );
    g_bgLoadFlag = 1;
}
