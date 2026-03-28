void SAnimator2_playFootprint(void*, char*);

void SAnimator2_footstepEvent(void* pThis, char* pName) {
    SAnimator2_playFootprint(pThis, pName);
}
