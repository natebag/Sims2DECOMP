/* 0x8005FF1C (100 bytes) - SAnimator2::followDoneUpdate(float &, float &, float) */
struct SAnimator2 {
    char pad[0x61C];
    unsigned int m_flags;
    void followDoneUpdate(float* turnAngle, float* desiredDir, float speed);
};
extern void setDesiredDir2(SAnimator2* self, float dir);
extern void rotateAnimation2(SAnimator2* self, float speed, float turnAngle, float desiredDir);

void SAnimator2::followDoneUpdate(float* turnAngle, float* desiredDir, float speed) {
    if (!(m_flags & 0x40)) {
        setDesiredDir2(this, *desiredDir);
    }
    rotateAnimation2(this, speed, *turnAngle, *desiredDir);
}
