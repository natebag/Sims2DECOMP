// 0x8001EA94 (8 bytes)
class ESimsCam {
public:
    float GetRotAng();
};

float ESimsCam::GetRotAng() {
    return *(float*)((char*)this + 0x44C);
}
