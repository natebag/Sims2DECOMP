// 0x80066F80 SAnimator2::lockCarryArmNodes(float*, int) (64B)
// Thunk: forwards to EAnimController::SetTrackBlendFactors(eTrackFlags, float*)
// with args swapped.  Same dead-load family as lockHandsUpCarryNodes (0x80066F00).
//
// Identical directive chain to 0x80066F40 variant; only the bl target differs:
//   0x80066F40 → SetTrackBlendFactors(EACTrack*, float*)   @ 0x802EF214
//   0x80066F80 → SetTrackBlendFactors(eTrackFlags, float*) @ 0x802EF230
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_region_gpr_relabel: start_anchor="stw 0,12(1)" start_mode=after end_anchor="lwz 0,12(1)" end_mode=before rename="0:11"
// ASMPROC_inject_before: before="mr 11, 4" lines="lwz 9,8(3)"
// ASMPROC_swap_adj: a=addi b=mr which=first
// ASMPROC_swap_adj: a=lwz b=mr which=1
// ASMPROC_inject_before: before="lwz 3,8(3)" lines="lwz 9,856(9); cmpwi 9,0"
// ASMPROC_swap_adj: a=addi b=mr which=first

enum eTrackFlags { eTrackFlags_OPAQUE = 0 };

class EAnimController {
public:
    void SetTrackBlendFactors(eTrackFlags flags, float* pFactors);
};

struct SAnimator2 {
    char pad[8];
    char* m_pSim;   // 0x008
    void lockCarryArmNodes(float* pArmNodes, eTrackFlags flags);
};

void SAnimator2::lockCarryArmNodes(float* pArmNodes, eTrackFlags flags) {
    EAnimController* ctrl = (EAnimController*)(m_pSim + 820);
    ctrl->SetTrackBlendFactors(flags, pArmNodes);
}
