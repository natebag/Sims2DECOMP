// 0x8001EA6C (8 bytes)
class ESimsCam {
public:
    int GetWin();
};

int ESimsCam::GetWin() {
    return (int)((char*)this + 0x10);
}
