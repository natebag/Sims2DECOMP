/* BGCall_ReloadObjectQuickdata(void) at 0x80014F30 (72B) */
// FLAGS: -fno-elide-constructors

extern void *g_bgm;
extern int g_bgf;
extern void BG_target_0x80014F30(void);

struct BGVt_0x80014F30 { char pad[0x40]; short m_off; char _p[2]; int (*m_fn)(void *, void (*)(void)); };
struct BGMgr_0x80014F30 { BGVt_0x80014F30 *m_vt; };

void BGCall_ReloadObjectQuickdata_void_(void) {
    BGMgr_0x80014F30 *mgr = (BGMgr_0x80014F30 *)g_bgm;
    g_bgf = 0;
    BGVt_0x80014F30 *vt = mgr->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void (*)(void)) = vt->m_fn;
    fn((char *)mgr + off, BG_target_0x80014F30);
}
