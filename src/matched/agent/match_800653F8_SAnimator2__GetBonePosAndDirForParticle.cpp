typedef unsigned char u8;

void EAnimController_GetBonePosAndDir(void*, unsigned int, void*);

void SAnimator2_GetBonePosAndDirForParticle(u8* pThis, unsigned int boneIdx, void* pMat) {
    void* pData = *(void**)(pThis + 0x08);
    EAnimController_GetBonePosAndDir((u8*)pData + 0x334, boneIdx, pMat);
}
