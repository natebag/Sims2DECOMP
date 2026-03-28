typedef unsigned char u8;

float SAnimator2_getPersonDirection(u8*);

void SAnimator2_setAnimationDirectionToPersonDirection(u8* pThis) {
    float dir = SAnimator2_getPersonDirection(pThis);
    *(float*)(pThis + 0x30) = dir;
}
