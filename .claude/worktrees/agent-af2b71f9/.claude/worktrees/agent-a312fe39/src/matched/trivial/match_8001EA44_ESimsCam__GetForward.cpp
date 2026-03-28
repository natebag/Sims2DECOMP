// 0x8001EA44 (8 bytes)
class ESimsCam {
public:
    int GetForward();
};

int ESimsCam::GetForward() {
    return (int)((char*)this + 0x424);
}
