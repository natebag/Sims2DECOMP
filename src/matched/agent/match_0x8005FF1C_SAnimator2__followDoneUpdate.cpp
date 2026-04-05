typedef unsigned char u8;

void setDesiredDir2(u8*, float);
void rotateAnimation2(u8*, float, float, float);

void SAnimator2_followDoneUpdate(u8* self, float* turnAngle, float* desiredDir, float speed) {
    if (!(*(int*)(self + 0x61C) & 0x40)) {
        setDesiredDir2(self, *desiredDir);
    }
    rotateAnimation2(self, speed, *turnAngle, *desiredDir);
}
