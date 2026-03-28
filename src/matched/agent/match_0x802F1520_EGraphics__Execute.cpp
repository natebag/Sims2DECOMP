/* EGraphics::Execute(EDL *) at 0x802F1520 (56B) */

struct GfxExecVt { char pad[0x28]; short m_off; int (*m_fn)(void *, void *); };
struct GfxExecObj { char pad[0x338]; GfxExecVt *m_vt; };
extern GfxExecObj *g_gfxObj;

void EGraphics_Execute(void *edl) {
    GfxExecVt *vt = g_gfxObj->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)g_gfxObj + off, edl);
}
