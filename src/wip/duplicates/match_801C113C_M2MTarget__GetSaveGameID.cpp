// 0x801C113C (8 bytes)
class M2MTarget {
public:
    int GetSaveGameID();
};

int M2MTarget::GetSaveGameID() {
    return *(int*)((char*)this + 0x110);
}
