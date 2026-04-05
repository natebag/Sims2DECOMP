typedef unsigned char u8;

void stopSMOptionalMotionAnims(u8*);
void stopDCOptionalMotionAnims(u8*);
void loadDCOptionalMotionAnims(u8*);

void SAnimator2_CheckOptionalMotionAnimStatusOnStateChange(u8* self, int state) {
    if ((unsigned int)(state - 12) <= 2) {
        stopSMOptionalMotionAnims(self);
    } else {
        stopDCOptionalMotionAnims(self);
    }
    int field_2C = *(int*)(self + 0x2C);
    if (field_2C == 9 || field_2C == 0) {
        if (state != 9) {
            loadDCOptionalMotionAnims(self);
        }
    }
}
