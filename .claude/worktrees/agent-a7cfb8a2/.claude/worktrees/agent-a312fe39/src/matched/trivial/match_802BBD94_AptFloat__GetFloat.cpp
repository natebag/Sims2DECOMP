// 0x802BBD94 (8 bytes)
class AptFloat {
public:
    float GetFloat();
};

float AptFloat::GetFloat() {
    return *(float*)((char*)this + 0xC);
}
