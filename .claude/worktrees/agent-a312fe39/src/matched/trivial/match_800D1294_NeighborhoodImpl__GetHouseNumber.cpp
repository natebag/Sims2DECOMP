// 0x800D1294 (8 bytes)
class NeighborhoodImpl {
public:
    int GetHouseNumber();
};

int NeighborhoodImpl::GetHouseNumber() {
    return *(int*)((char*)this + 0x70);
}
