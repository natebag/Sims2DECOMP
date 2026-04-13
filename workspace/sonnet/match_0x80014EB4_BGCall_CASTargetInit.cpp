// 0x80014EB4 BGCall_CASTargetInit (76b)
// FLAGS: -fno-elide-constructors

extern void *g_bgm;
extern int g_bgfParam;
extern int g_bgfFlag;
extern void BG_target_0x80014EB4(void);

struct BGVt_CAS { char pad[0x40]; short m_off; char _p[2]; int (*m_fn)(void *, void (*)(void)); };
struct BGMgr_CAS { BGVt_CAS *m_vt; };

void BGCall_CASTargetInit(int param) {
    BGMgr_CAS *mgr = (BGMgr_CAS *)g_bgm;
    g_bgfParam = param;
    BGVt_CAS *vt = mgr->m_vt;
    g_bgfFlag = 0;
    short off = vt->m_off;
    int (*fn)(void *, void (*)(void)) = vt->m_fn;
    fn((char *)mgr + off, BG_target_0x80014EB4);
}
