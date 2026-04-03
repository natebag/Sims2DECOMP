// 0x801491F4 (8 bytes)
class TreeSim {
public:
    void setMTObjectImpl(int p);
};

void TreeSim::setMTObjectImpl(int p) {
    *(int*)((char*)this + 0x8) = p;
}
