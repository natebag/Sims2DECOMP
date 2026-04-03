// 0x8001EA3C (8 bytes)
class ESimsCam {
public:
    int GetUp();
};

int ESimsCam::GetUp() {
    return (int)((char*)this + 0x424);
}
