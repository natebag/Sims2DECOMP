// 0x8006982C SAnimator2::updateDesiredAndDeltaDir(float&, float&) (68B)
// Pattern: two chained internal calls with float-arg-passthrough
struct SAnimator2 {
    float getDesiredDir();
    float getDeltaDirFromDesiredDir(float);
    void updateDesiredAndDeltaDir(float& out1, float& out2);
};

void SAnimator2::updateDesiredAndDeltaDir(float& out1, float& out2) {
    float f = getDesiredDir();
    out1 = f;
    out2 = getDeltaDirFromDesiredDir(f);
}
