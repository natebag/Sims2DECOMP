// 0x80066F40 SAnimator2::lockCarryArmNodes(float*, EACTrack*) (64B)
// Thunk: forwards to EAnimController::SetTrackBlendFactors(EACTrack*, float*)
// with args swapped.  Same dead-load family as lockHandsUpCarryNodes (0x80066F00).
//
// GCC uses r0 as arg-save tmp; DOL uses r11. region_gpr_relabel 0:11 in body.
// Dead-load inject: two inject_before directives.
// Instruction reordering: 3 swap_adj directives.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_region_gpr_relabel: start_anchor="stw 0,12(1)" start_mode=after end_anchor="lwz 0,12(1)" end_mode=before rename="0:11"
// ASMPROC_inject_before: before="mr 11, 4" lines="lwz 9,8(3)"
// ASMPROC_swap_adj: a=addi b=mr which=first
// ASMPROC_swap_adj: a=lwz b=mr which=1
// ASMPROC_inject_before: before="lwz 3,8(3)" lines="lwz 9,856(9); cmpwi 9,0"
// ASMPROC_swap_adj: a=addi b=mr which=first

struct EACTrack;

class EAnimController {
public:
    void SetTrackBlendFactors(EACTrack* pTrack, float* pFactors);
};

struct SAnimator2 {
    char pad[8];
    char* m_pSim;   // 0x008
    void lockCarryArmNodes(float* pArmNodes, EACTrack* pTrack);
};

void SAnimator2::lockCarryArmNodes(float* pArmNodes, EACTrack* pTrack) {
    EAnimController* ctrl = (EAnimController*)(m_pSim + 820);
    ctrl->SetTrackBlendFactors(pTrack, pArmNodes);
}
