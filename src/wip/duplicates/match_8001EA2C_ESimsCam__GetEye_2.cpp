// 0x8001EA2C (8 bytes)
class ESimsCam {
public:
    int GetEye();
};

int ESimsCam::GetEye() {
    return (int)((char*)this + 0x418);
}
