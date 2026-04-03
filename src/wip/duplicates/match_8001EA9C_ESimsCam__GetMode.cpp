// 0x8001EA9C (8 bytes)
class ESimsCam {
public:
    int GetMode();
};

int ESimsCam::GetMode() {
    return *(int*)((char*)this + 0x3CC);
}
