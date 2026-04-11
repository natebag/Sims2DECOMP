// 0x80014C14 BGExec_LoadHouse (88b)
// FLAGS: -fno-elide-constructors

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
    void *arg2 = g_houseNameArg;
    BGLoadVt *vt = mgr->m_vt;
    int arg3 = _globals.m_field_C8->m_field_54;
    int (*fn)(void *, void *, int, int) = vt->m_fn;
    short off = vt->m_off;
    int arg4 = _globals.m_field_158;
    fn((char *)mgr + off, arg2, arg3, arg4);
    g_bgLoadFlag = 1;
}
