// 0x8014920C (8 bytes)
class TreeSim {
public:
    int GetBaseISimInstance();
};

int TreeSim::GetBaseISimInstance() {
    return *(int*)((char*)this + 0x10);
}
