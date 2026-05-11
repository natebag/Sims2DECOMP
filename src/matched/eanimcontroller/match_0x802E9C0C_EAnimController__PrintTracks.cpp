// 0x802E9C0C EAnimController::PrintTracks(void) (24B)
//
// PHASE 2 WALL — OpusReviewGuy park 2026-05-11.
// Empty count-down loop: for (int i = m_field_40; i > 0; --i) {}
// DOL: lwz r0, 64(r3); cmpwi r0, 0; blelr; mtctr r0; bdnz $-0; blr
// GCC: lwz r3, 64(r3); mtctr r3; cmpwi r3, 0; blelr; ...
// Two issues: (a) register choice (r3 vs r0); (b) mtctr position (before vs after blelr).
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_force_reg_at_pos: match="lwz 3,64(3)" pos=0 from_reg=3 to_reg=0
// ASMPROC_force_reg_at_pos: match="mtctr 3" pos=0 from_reg=3 to_reg=0
// ASMPROC_force_reg_at_pos: match="cmpwi 0,3,0" pos=1 from_reg=3 to_reg=0
// ASMPROC_swap_adj: a=mtctr b=cmpwi which=first
// ASMPROC_swap_adj: a=mtctr b=bclr which=first

class EAnimController {
public:
    char  pad[64];     // 0x00..0x3F
    int   m_field_40;  // 0x40 (offset 64)

    void PrintTracks();
};

void EAnimController::PrintTracks()
{
    int n = m_field_40;
    if (n <= 0) return;
    do {} while (--n);
}
