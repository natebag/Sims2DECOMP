// 0x8022A644 (8 bytes)
class EIPointLight {
public:
    float GetFalloffEnd();
};

float EIPointLight::GetFalloffEnd() {
    return *(float*)((char*)this + 0xC8);
}
