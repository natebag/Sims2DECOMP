// 0x800D18A8 (8 bytes)
class NeighborhoodImpl {
public:
    short GetHighestLevelCompleted();
};

short NeighborhoodImpl::GetHighestLevelCompleted() {
    return *(short*)((char*)this + 0x84);
}
