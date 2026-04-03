// 0x8001EA8C (8 bytes)
class ESimsCam {
public:
    int GetbMoved();
};

int ESimsCam::GetbMoved() {
    return *(int*)((char*)this + 0x8);
}
