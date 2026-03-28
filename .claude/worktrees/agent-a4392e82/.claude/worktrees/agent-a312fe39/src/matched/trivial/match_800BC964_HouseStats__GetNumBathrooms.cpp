// 0x800BC964 (8 bytes)
class HouseStats {
public:
    int GetNumBathrooms();
};

int HouseStats::GetNumBathrooms() {
    return *(int*)((char*)this + 0xC);
}
