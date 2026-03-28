// 0x801491EC (8 bytes)
class TreeSim {
public:
    void setPersonImpl(int p);
};

void TreeSim::setPersonImpl(int p) {
    *(int*)((char*)this + 0x4) = p;
}
