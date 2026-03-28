// 0x801491E4 (8 bytes)
class TreeSim {
public:
    void setObjectImpl(int p);
};

void TreeSim::setObjectImpl(int p) {
    *(int*)((char*)this + 0x0) = p;
}
