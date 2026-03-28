// 0x8014921C (8 bytes)
class TreeSim {
public:
    int GetESimPerson();
};

int TreeSim::GetESimPerson() {
    return *(int*)((char*)this + 0x14);
}
