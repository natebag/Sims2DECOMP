// 0x80149224 (8 bytes)
class TreeSim {
public:
    void SetESimPerson(int p);
};

void TreeSim::SetESimPerson(int p) {
    *(int*)((char*)this + 0x14) = p;
}
