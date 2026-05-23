/* 0x80066470 (8 bytes) - SAnimator2::footstepEvent(char*) */
void SAnimator2_playFootprint(void*, char*);

struct SAnimator2 {
    void footstepEvent(char* pName);
};

void SAnimator2::footstepEvent(char* pName) {
    SAnimator2_playFootprint(this, pName);
}
