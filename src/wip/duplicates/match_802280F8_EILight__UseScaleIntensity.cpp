// 0x802280F8 (8 bytes)
class EILight {
public:
    void UseScaleIntensity(int p);
};

void EILight::UseScaleIntensity(int p) {
    *(int*)((char*)this + 0xA8) = p;
}
