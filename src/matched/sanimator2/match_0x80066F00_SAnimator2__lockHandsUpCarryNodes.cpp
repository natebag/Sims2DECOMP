// 0x80066F00 SAnimator2::lockHandsUpCarryNodes(void) (64B)
//
// PHASE 2 — DRIFT RECOVERY + inject_before triplet validation #1.
// Prior match drifted (volatile u8* dead-load elided by current GCC); moved
// to src/wip/version_diff/session15_recovery/. Fresh derivation here.
//
// DOL has 4 dead-load insns before the controller call:
//   lwz r9, 8(r3)        ; m_inner
//   lwz r9, 856(r9)      ; m_inner->slot at +856 (the dead value)
//   cmpwi r9, 0          ; test (no branch — pure assertion-style)
//   lwz r3, 8(r3)        ; reload m_inner because r9 was clobbered
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_inject_before: before="lwz 3,8(3)" lines="lwz 9,8(3); lwz 9,856(9); cmpwi 9,0"
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=addi b=lis which=first
// ASMPROC_swap_adj: a=li b=la which=first
// ASMPROC_swap_adj: a=addi b=la which=first
// ASMPROC_swap_adj: a=addi b=li which=first

enum eTrackFlags { kFlags_HandsUpCarry = 2048 };

class EAnimController {
public:
    void SetTrackBlendFactors(eTrackFlags t, float* p);
};

extern float lbl_804FB978[3];   // 0x80500000 + sign_ext(-18056) = 0x804FB978

struct SAnimator2 {
    char  pad[8];
    char* m_inner;       // 0x008

    void lockHandsUpCarryNodes();
};

void SAnimator2::lockHandsUpCarryNodes()
{
    EAnimController* ctrl = (EAnimController*)(m_inner + 820);
    ctrl->SetTrackBlendFactors(kFlags_HandsUpCarry, lbl_804FB978);
}
