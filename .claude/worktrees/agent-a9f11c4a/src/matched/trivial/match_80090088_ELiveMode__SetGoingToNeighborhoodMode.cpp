// 0x80090088 (8 bytes)
class ELiveMode {
public:
    void SetGoingToNeighborhoodMode(int p);
};

void ELiveMode::SetGoingToNeighborhoodMode(int p) {
    *(int*)((char*)this + 0x24) = p;
}
