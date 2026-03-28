// 0x80228160 (8 bytes)
class EILight {
public:
    void SetIntensity(float p);
};

void EILight::SetIntensity(float p) {
    *(float*)((char*)this + 0x8C) = p;
}
