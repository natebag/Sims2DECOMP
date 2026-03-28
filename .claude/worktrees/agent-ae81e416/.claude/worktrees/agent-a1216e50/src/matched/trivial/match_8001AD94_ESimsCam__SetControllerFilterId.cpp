// 0x8001AD94 (8 bytes)
class ESimsCam {
public:
    int SetControllerFilterId(int p);
};

int ESimsCam::SetControllerFilterId(int p) {
    *(int*)((char*)this + 0x560) = p; return 1;
}
