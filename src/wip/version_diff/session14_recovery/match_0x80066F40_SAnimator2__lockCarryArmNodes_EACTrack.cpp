// 0x80066F40 SAnimator2::lockCarryArmNodes(float *, EACTrack *) (64B)
// Sibling-port from 0x80066F00 lockHandsUpCarryNodes — same dead-load + controller-call shape,
// but parameter order (float*, EACTrack*) requires r4<->r5 swap before call to
// EAnimController::SetTrackBlendFactors(EACTrack*, float*).
typedef unsigned char u8;

extern void SetTrackBlendFactors_EACTrack(u8* ctrl, void* track, float* p);

void SAnimator2_lockCarryArmNodes_EACTrack(u8* self, float* p, void* track) {
    volatile u8* data = *(volatile u8**)(self + 8);
    volatile u8* ptr = *(volatile u8**)((u8*)data + 0x358);
    (void)ptr;
    SetTrackBlendFactors_EACTrack((u8*)data + 0x334, track, p);
}
