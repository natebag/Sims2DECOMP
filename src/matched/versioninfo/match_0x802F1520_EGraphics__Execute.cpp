/* EGraphics::Execute(EDL *) at 0x802F1520 (56B) */

struct GfxExecVt { char pad[0x28]; short m_off; int (*m_fn)(void *, void *); };
struct GfxExecObj { char pad[0x338]; GfxExecVt *m_innerVt; };
extern GfxExecObj *g_gfxObj;

struct EGraphics_E {
    void Execute(void *edl);
};

void EGraphics_E::Execute(void *edl) {
    GfxExecObj *obj = g_gfxObj;
    GfxExecVt *vt = obj->m_innerVt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)obj + off, edl);
}
