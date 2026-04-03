// 0x8001EA7C (8 bytes)
class ESimsCam {
public:
    float GetTilt();
};

float ESimsCam::GetTilt() {
    return *(float*)((char*)this + 0x450);
}
