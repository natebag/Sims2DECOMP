// 0x80228168 (8 bytes)
class EILight {
public:
    float GetIntensity();
};

float EILight::GetIntensity() {
    return *(float*)((char*)this + 0x8C);
}
