// 0x800BC974 (8 bytes)
class HouseStats {
public:
    int GetLotSize();
};

int HouseStats::GetLotSize() {
    return *(int*)((char*)this + 0x14);
}
