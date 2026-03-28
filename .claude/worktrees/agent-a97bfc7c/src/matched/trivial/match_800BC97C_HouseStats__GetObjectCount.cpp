// 0x800BC97C (8 bytes)
class HouseStats {
public:
    int GetObjectCount();
};

int HouseStats::GetObjectCount() {
    return *(int*)((char*)this + 0x24);
}
