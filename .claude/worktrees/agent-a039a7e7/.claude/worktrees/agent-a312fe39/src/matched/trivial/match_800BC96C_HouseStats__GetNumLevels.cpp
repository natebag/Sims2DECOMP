// 0x800BC96C (8 bytes)
class HouseStats {
public:
    int GetNumLevels();
};

int HouseStats::GetNumLevels() {
    return *(int*)((char*)this + 0x10);
}
