/* BGCall_LoadDefaultNeighborhood(void) at 0x80014BCC (72B) */
// FLAGS: -fno-elide-constructors

extern void *g_bgManager;
extern int g_bgFlag;
extern void BG_LoadDefaultNeighborhood(void);

struct BGVt { char pad[0x40]; short m_off; char _p[2]; int (*m_fn)(void *, void (*)(void)); };
struct BGMgr { BGVt *m_vt; };

void BGCall_LoadDefaultNeighborhood(void) {
    BGMgr *mgr = (BGMgr *)g_bgManager;
    g_bgFlag = 0;
    BGVt *vt = mgr->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void (*)(void)) = vt->m_fn;
    fn((char *)mgr + off, BG_LoadDefaultNeighborhood);
}
