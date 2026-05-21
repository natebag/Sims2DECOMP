// 0x803009D4 (28B) EWindow::TransformScale(float, float, float &, float &)

class EWindow {
public:
    void TransformScale(float x, float y, float& xOut, float& yOut);
};

void EWindow::TransformScale(float x, float y, float& xOut, float& yOut) {
    xOut = x * *(float*)this;
    yOut = y * *(float*)((char*)this + 20);
}
