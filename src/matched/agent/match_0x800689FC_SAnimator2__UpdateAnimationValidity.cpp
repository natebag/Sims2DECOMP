// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

void SAnimator2_UpdateAnimationValidity(u8* self) {
    u8* data = *(u8**)(self + 0x08);
    int isValid = 1;
    u8* animCtrl = data + 0x334;
    int trackIdx = *(int*)(animCtrl + 8);
    int result;
    if (trackIdx >= 0) {
        result = *(int*)(animCtrl + 0x44) + trackIdx * 176;
    } else {
        result = 0;
    }
    if (result == 0) {
        isValid = 0;
    }
    *(int*)(*(u8**)(self + 0x08) + 0x394) = isValid;
}
