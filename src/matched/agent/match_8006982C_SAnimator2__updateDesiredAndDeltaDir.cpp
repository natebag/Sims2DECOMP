struct SAnimator2 {
    float getDesiredDir();
    float getDeltaDirFromDesiredDir(float);
    void updateDesiredAndDeltaDir(float*, float*);
};

void SAnimator2::updateDesiredAndDeltaDir(float* pDesired, float* pDelta) {
    float desired = getDesiredDir();
    *pDesired = desired;
    float delta = getDeltaDirFromDesiredDir(desired);
    *pDelta = delta;
}
