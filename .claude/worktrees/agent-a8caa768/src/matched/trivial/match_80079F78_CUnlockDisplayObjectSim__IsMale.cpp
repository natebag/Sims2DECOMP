// 0x80079F78 (8 bytes)
class CUnlockDisplayObjectSim {
public:
    int IsMale();
};

int CUnlockDisplayObjectSim::IsMale() {
    return *(int*)((char*)(*(int*)((char*)this + 0x1B4)) + 0x84);
}
