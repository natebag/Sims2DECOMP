// 0x801492B4 (8 bytes)
class TreeSimImpl {
public:
    void SetNoMainTreeSim(int p);
};

void TreeSimImpl::SetNoMainTreeSim(int p) {
    *(int*)((char*)this + 0x38) = p;
}
