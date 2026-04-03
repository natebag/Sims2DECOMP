// 0x8001EA84 (8 bytes)
class ESimsCam {
public:
    void SetTilt(float p);
};

void ESimsCam::SetTilt(float p) {
    *(float*)((char*)this + 0x450) = p;
}
