// 0x800DCE00 PlacementSpec::PlacementSpec(FTilePt&, int, cXObjectImpl*, int) (68B)
//
// Builds a placement record from either an existing object's tile position
// (obj->[104..111]) or a passed-in FTilePt — same store layout for both
// paths but the source pointer is conditionally chosen.
//
// WALL CLASS: load-pair swap + 3-way register-allocation rotation
//   DOL emits `lwz r9,0(r4); lwz r10,4(r4)` then `stw r9,4(r3); stw r10,8(r3)`.
//   GCC emits the loads in reverse offset order (`lwz r9,4; lwz r0,0`) and
//   uses r0 instead of r10 for the second value. Semantically identical
//   — same 4 bytes copied — but the register/order divergence is pure.
//
// Recipe (5 existing-mutator directives — no new mutator needed):
//   1. swap_adj a=lwz b=lwz                       (swap to DOL's load order)
//   2. force_reg_at_pos lwz 9,4 dest 9->10        (rename r9 dest -> r10)
//   3. force_reg_at_pos lwz 0,0 dest 0->9         (rename r0 dest -> r9)
//   4. force_reg_at_pos stw 9,8 src 9->10         (paired stw r9 -> r10)
//   5. force_reg_at_pos stw 0,4 src 0->9          (paired stw r0 -> r9)
//
// Direct application of feedback `swap_operands_lwzx_n3` plus site-specific
// renames. This is a textbook example of "load-pair-canonicalization-defeat"
// — pattern is likely repeatable in other small ctors that copy a 2-word
// field pair via conditional pointer.
//
// Parked by OpusReviewGuy 2026-05-21 with diff_func.sh output.
//
// ASMPROC_swap_adj: a=lwz b=lwz which=first
// ASMPROC_force_reg_at_pos: match="lwz 9,4(4)" pos=0 from_reg=9 to_reg=10
// ASMPROC_force_reg_at_pos: match="lwz 0,0(4)" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="stw 9,8(3)" pos=0 from_reg=9 to_reg=10
// ASMPROC_force_reg_at_pos: match="stw 0,4(3)" pos=0 from_reg=0 to_reg=9

struct FTilePt {
    int x, y;
};

class cXObjectImpl;

class PlacementSpec {
public:
    int m_0;
    int m_4;
    int m_8;
    cXObjectImpl* m_12;
    int m_16;
    int m_20;

    PlacementSpec(FTilePt& tile, int arg2, cXObjectImpl* obj, int arg4);
};

PlacementSpec::PlacementSpec(FTilePt& tile, int arg2, cXObjectImpl* obj, int arg4) {
    m_0 = 1;
    char* p;
    if (obj != 0) {
        p = (char*)obj + 104;
    } else {
        p = (char*)&tile;
    }
    int v9 = *(int*)p;
    int v10 = *(int*)(p + 4);
    m_12 = obj;
    m_4 = v9;
    m_8 = v10;
    if (obj != 0) {
        m_16 = arg4;
    } else {
        m_16 = -1;
    }
    m_20 = arg2;
}
