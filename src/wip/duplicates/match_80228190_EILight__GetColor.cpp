// 0x80228190 (8 bytes)
class EILight {
public:
    int GetColor();
};

int EILight::GetColor() {
    return (int)((char*)this + 0x90);
}
