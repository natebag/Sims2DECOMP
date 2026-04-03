// 0x80149204 (8 bytes)
class TreeSim {
public:
    int GetPerson();
};

int TreeSim::GetPerson() {
    return *(int*)((char*)this + 0x4);
}
