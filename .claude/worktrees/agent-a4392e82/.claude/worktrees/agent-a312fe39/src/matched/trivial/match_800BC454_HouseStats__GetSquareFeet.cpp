// 0x800BC454 (8 bytes)
class HouseStats {
public:
    int GetSquareFeet();
};

int HouseStats::GetSquareFeet() {
    return *(int*)((char*)this + 0x0);
}
