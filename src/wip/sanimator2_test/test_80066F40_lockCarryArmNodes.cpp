typedef unsigned char u8;
typedef unsigned int u32;

class EACTrack;

class EAnimController {
public:
    void SetTrackBlendFactors(EACTrack* track, float* factors);
};

class ESim {
public:
    char pad[0x334];
    EAnimController m_animController;
};

struct SAnimator2 {
    char pad[0x8];
    ESim* m_pSim;
};

void SAnimator2_lockCarryArmNodes(SAnimator2* self, float* factors, EACTrack* track) {
    ESim* sim = self->m_pSim;
    if (*(void**)((char*)sim + 0x358)) {
        self->m_pSim->m_animController.SetTrackBlendFactors(track, factors);
    }
}
