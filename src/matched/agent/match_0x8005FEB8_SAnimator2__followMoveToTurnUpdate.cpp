typedef unsigned char u8;

void setDesiredDir(u8*, float);
void rotateAnimation(u8*, float, float, float);

void SAnimator2_followMoveToTurnUpdate(u8* self, float* turnAngle, float* desiredDir, float speed) {
    if (!(*(int*)(self + 0x61C) & 0x40)) {
        setDesiredDir(self, *desiredDir);
    }
    rotateAnimation(self, speed, *turnAngle, *desiredDir);
}
