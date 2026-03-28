// 0x800BC95C (8 bytes)
class HouseStats {
public:
    int GetNumBedrooms();
};

int HouseStats::GetNumBedrooms() {
    return *(int*)((char*)this + 0x8);
}
