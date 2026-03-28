// 0x800D1950 (8 bytes)
class NeighborhoodImpl {
public:
    void SetHouseNum(int p);
};

void NeighborhoodImpl::SetHouseNum(int p) {
    *(int*)((char*)this + 0x70) = p;
}
