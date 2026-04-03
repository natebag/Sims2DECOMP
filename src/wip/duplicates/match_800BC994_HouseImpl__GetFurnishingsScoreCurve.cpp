// 0x800BC994 (8 bytes)
class HouseImpl {
public:
    int GetFurnishingsScoreCurve();
};

int HouseImpl::GetFurnishingsScoreCurve() {
    return *(int*)((char*)this + 0x20);
}
