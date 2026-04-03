// 0x801491FC (8 bytes)
class TreeSim {
public:
    void setPortalImpl(int p);
};

void TreeSim::setPortalImpl(int p) {
    *(int*)((char*)this + 0xC) = p;
}
