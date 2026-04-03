// 0x8001EADC (8 bytes)
class ESimsCam {
public:
    void SetInterpolatingFromLotIntroCameraFlag(int p);
};

void ESimsCam::SetInterpolatingFromLotIntroCameraFlag(int p) {
    *(int*)((char*)this + 0x568) = p;
}
