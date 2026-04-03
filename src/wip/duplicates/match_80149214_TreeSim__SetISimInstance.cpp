// 0x80149214 (8 bytes)
class TreeSim {
public:
    void SetISimInstance(int p);
};

void TreeSim::SetISimInstance(int p) {
    *(int*)((char*)this + 0x10) = p;
}
