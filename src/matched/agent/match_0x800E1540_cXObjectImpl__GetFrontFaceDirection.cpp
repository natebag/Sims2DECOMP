// FLAGS: -fno-schedule-insns
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9,140(3)" end_anchor="add 3,10,3" rename="9:4,10:11,11:9"
// cXObjectImpl::GetFrontFaceDirection(void) at 0x800E1540 (84B)
//
// Vtable-slot-N-via-N-1-fillers (slot 20 = byte 160) returning a "front face"
// resource pointer; if non-null, returns short m_dir at offset 122 of the
// resource's data ptr (offset 56). Class layout: m_inner at offset 140, then
// inner has Holder* at offset 80, holder has vtable ptr at offset 0.
//
// Source emits the correct block layout natively after early-return polarity
// (`if (res == 0) return 0;`). Residual diff was pure register-coloring:
// cc1plus picked r9/r10/r11 for inner-load/holder/vt; DOL uses r4/r11/r9 with
// holder kept in r11 across the call setup. region_gpr_relabel rewrites the
// 6-instruction load/setup region with directed map 9:4,10:11,11:9.

struct GFFVt1 { char pad[0xA0]; short m_off; char _p[2]; void *(*m_fn)(void *); };
struct GFFHolder { GFFVt1 *m_vt; };
struct GFFInner { char pad[0x50]; GFFHolder *m_h; };

struct GFFData { char pad[0x7A]; short m_dir; };
struct GFFResult { char pad[0x38]; GFFData *m_data; };

struct cXObjFFD {
    char pad[0x8C];
    GFFInner *m_inner;
    int GetFrontFaceDirection(void);
};

int cXObjFFD::GetFrontFaceDirection(void) {
    GFFHolder *h = m_inner->m_h;
    GFFVt1 *vt = h->m_vt;
    short off = vt->m_off;
    void *(*fn)(void *) = vt->m_fn;
    GFFResult *res = (GFFResult *)fn((char *)h + off);
    if (res == 0) return 0;
    return res->m_data->m_dir;
}
