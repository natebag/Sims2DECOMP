// 0x8001EABC (8 bytes)
class ESimsCam {
public:
    void SetCenterNew(int p);
};

void ESimsCam::SetCenterNew(int p) {
    *(int*)((char*)this + 0x540) = p;
}
