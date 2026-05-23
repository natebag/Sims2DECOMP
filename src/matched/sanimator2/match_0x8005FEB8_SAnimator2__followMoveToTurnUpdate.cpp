/* 0x8005FEB8 (100 bytes) - SAnimator2::followMoveToTurnUpdate(float &, float &, float) */
struct SAnimator2 {
    char pad[0x61C];
    unsigned int m_flags;
    void followMoveToTurnUpdate(float* turnAngle, float* desiredDir, float speed);
};
extern void setDesiredDir(SAnimator2* self, float dir);
extern void rotateAnimation(SAnimator2* self, float speed, float turnAngle, float desiredDir);

void SAnimator2::followMoveToTurnUpdate(float* turnAngle, float* desiredDir, float speed) {
    if (!(m_flags & 0x40)) {
        setDesiredDir(this, *desiredDir);
    }
    rotateAnimation(this, speed, *turnAngle, *desiredDir);
}
