/* 0x800653F8 (32 bytes) - SAnimator2::GetBonePosAndDirForParticle(unsigned, void*) */
typedef unsigned char u8;

void EAnimController_GetBonePosAndDir(void*, unsigned int, void*);

struct SAnimator2 {
    char pad[8];
    void* m_pSim;
    void GetBonePosAndDirForParticle(unsigned int boneIdx, void* pMat);
};

void SAnimator2::GetBonePosAndDirForParticle(unsigned int boneIdx, void* pMat) {
    EAnimController_GetBonePosAndDir((u8*)m_pSim + 0x334, boneIdx, pMat);
}
