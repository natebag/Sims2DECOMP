// 0x8012B5A0 cXPersonImpl::InvalidateRoutes (52B)
// ASMPROC_insert_mr: after=bclr src=11 dst=3 relabel=10:11,11:3
//
// Cracked S13 session 2 (2026-05-01) via newly-authored insert_mr mutator
// (Track I Phase 3). 12 of 13 insns produced by natural source-coax via
// `base = &m_start; base[0]/base[1] entry + base[1] loop re-read`; the 13th
// insn (`mr r3, r11`) is GCC-RA-unforceable and is now synthesized by the
// mutator post-compile, with downstream relabel of r10→r11 (zero-store) and
// r11→r3 (loop re-read) producing byte-exact match against DOL.

struct RouteNode {
    char pad[0x7C];
    int field_7C;
    char pad2[0x24];
};

struct cXPersonImpl {
    char pad[0x40C];
    RouteNode* m_start;
    RouteNode* m_end;
    void InvalidateRoutes();
};

void cXPersonImpl::InvalidateRoutes() {
    RouteNode** base = &m_start;
    RouteNode* p = base[0];
    if (p == base[1]) return;
    do {
        p->field_7C = 0;
        p++;
    } while (p != base[1]);
}
