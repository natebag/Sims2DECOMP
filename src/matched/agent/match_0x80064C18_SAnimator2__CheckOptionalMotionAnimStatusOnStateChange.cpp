typedef unsigned char u8;

extern void CheckOptionalMotionA(u8* self);
extern void CheckOptionalMotionB(u8* self);
extern void CheckOptionalMotionC(u8* self);

void SAnimator2_CheckOptionalMotionAnimStatusOnStateChange(u8* self, int state) {
    if ((unsigned int)(state - 12) <= 2) {
        CheckOptionalMotionA(self);
    } else {
        CheckOptionalMotionB(self);
    }
    int field_2c = *(int*)(self + 0x2C);
    if ((field_2c == 9 || field_2c == 0) && state != 9) {
        CheckOptionalMotionC(self);
    }
}
