// 0x8001EAB4 (8 bytes)
class ESimsCam {
public:
    int IsForceFullScreen();
};

int ESimsCam::IsForceFullScreen() {
    return *(int*)((char*)this + 0x54C);
}
