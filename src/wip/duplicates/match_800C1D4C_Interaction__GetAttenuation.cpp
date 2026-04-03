// 0x800C1D4C (8 bytes)
class Interaction {
public:
    float GetAttenuation();
};

float Interaction::GetAttenuation() {
    return *(float*)((char*)this + 0x30);
}
