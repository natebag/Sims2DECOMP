// ASMPROC_region_gpr_relabel: start_anchor="lwz 0,0(9)" end_anchor="stw 10,8(8)" rename="0:11,11:10,10:0"
// ASMPROC_swap_adj: a=stw b=stw which=last
//
// Category 2 wall — register coloring + store-order residual.
//
// DIAGNOSIS (2026-05-23, SonnetWorker2, S18):
// var3 source structure (m_immediateCut first, then loads/stores) matches DOL
// instruction skeleton exactly: li -> mr -> stw(const) -> addi -> 3x loads -> 3x stores.
//
// The compiler version difference causes two divergences:
//   (a) REGISTER COLORING: DOL's SN ProDG uses "cascade displacement" when
//       the scheduler inserts `mr r9,r4` (pos_copy): x is displaced from r9 and
//       takes cp's former register (r11), then cp moves to r8. Our SN ProDG uses
//       "grab-available": x grabs the first free register (r0, freed by the constant's
//       stw). Result is a cyclic rotation: DOL has x->r11,y->r10,z->r0;
//       ours has x->r0,y->r11,z->r10.
//
//   (b) STORE ORDER: Because z uses r0 in DOL (low pressure), the scheduler
//       prioritizes cp[2]=z before cp[1]=y (freeing r0 early for post-call use).
//       In our version, x uses r0 so no early-free urgency — stores come out
//       address-sorted: cp[0], cp[1], cp[2].
//
// The two ASMPROC directives fix both issues atomically:
//   1. region_gpr_relabel: cyclic rename {r0->r11, r11->r10, r10->r0} in the
//      6-instruction region [lwz x ... stw cp[2]], using start_mode="at"
//      (kill-point semantic on the first load's dest) and end_mode="at".
//      Cyclic rename means floating_to is empty so all liveness checks pass.
//   2. swap_adj stw/stw which=last: after relabeling, the two final stores are
//      stw 10,4(8) [cp[1]=y] then stw 0,8(8) [cp[2]=z]. Swap them to match
//      DOL's cp[2]-before-cp[1] order. "last" targets the second of the two
//      adjacent stw/stw pairs (the cp[1]/cp[2] pair, not cp[0]/cp[1]).
//
// Verified transformation:
//   BEFORE (var3 compiled):                 AFTER (DOL):
//   lwz 0,0(9)   [x=r0]      ->  lwz 11,0(9)  [x=r11]
//   lwz 11,4(9)  [y=r11]     ->  lwz 10,4(9)  [y=r10]
//   lwz 10,8(9)  [z=r10]     ->  lwz 0,8(9)   [z=r0]
//   stw 0,8(3)   [cp[0]=x]   ->  stw 11,8(3)  [cp[0]=x]
//   stw 11,4(8)  [cp[1]=y]   ->  stw 0,8(8)   [cp[2]=z]  (swapped)
//   stw 10,8(8)  [cp[2]=z]   ->  stw 10,4(8)  [cp[1]=y]  (swapped)
//
namespace InteractorModule {
struct EVec3 { int x, y, z; };
extern void _CutCameraToPos_s8021E6E0(void* cam, EVec3* pos);
struct SimInteractor {
    int m_pad0;
    void* m_cameraTarget;
    int m_cursorPos[3];
    char m_pad1[0x178];
    int m_immediateCut;
    void ImmediatelyCutCursorAndCameraToPos(EVec3* pos);
};
void SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3* pos) {
    m_immediateCut = 1;
    int* cp = m_cursorPos;
    int x = pos->x;
    int y = pos->y;
    int z = pos->z;
    cp[0] = x;
    cp[2] = z;
    cp[1] = y;
    _CutCameraToPos_s8021E6E0(m_cameraTarget, pos);
}
}
