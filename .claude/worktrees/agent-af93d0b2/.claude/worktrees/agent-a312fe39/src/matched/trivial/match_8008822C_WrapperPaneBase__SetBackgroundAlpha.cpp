// 0x8008822C (8 bytes)
class WrapperPaneBase {
public:
    void SetBackgroundAlpha(float p);
};

void WrapperPaneBase::SetBackgroundAlpha(float p) {
    *(float*)((char*)this + 0x2C) = p;
}
