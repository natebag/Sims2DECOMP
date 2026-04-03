// 0x80087ADC (8 bytes)
class WrapperPaneBase {
public:
    float GetAlpha();
};

float WrapperPaneBase::GetAlpha() {
    return *(float*)((char*)this + 0x30);
}
