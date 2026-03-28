struct EVec2 {
    float x;
    float y;
};

struct EWindow {
    int ClipTest(float x, float y);
    int ClipTest(EVec2& v);
};

int EWindow::ClipTest(EVec2& v) {
    return ClipTest(v.x, v.y);
}
