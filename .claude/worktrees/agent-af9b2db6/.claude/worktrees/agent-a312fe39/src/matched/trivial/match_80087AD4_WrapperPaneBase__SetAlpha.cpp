// 0x80087AD4 (8 bytes)
class WrapperPaneBase {
public:
    void SetAlpha(float p);
};

void WrapperPaneBase::SetAlpha(float p) {
    *(float*)((char*)this + 0x30) = p;
}
