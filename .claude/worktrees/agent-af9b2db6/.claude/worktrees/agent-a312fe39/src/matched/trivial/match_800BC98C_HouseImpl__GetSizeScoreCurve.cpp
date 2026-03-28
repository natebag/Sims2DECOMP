// 0x800BC98C (8 bytes)
class HouseImpl {
public:
    int GetSizeScoreCurve();
};

int HouseImpl::GetSizeScoreCurve() {
    return *(int*)((char*)this + 0x1C);
}
