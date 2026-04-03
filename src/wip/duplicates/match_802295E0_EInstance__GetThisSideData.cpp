// 0x802295E0 (8 bytes)
class EInstance {
public:
    int GetThisSideData();
};

int EInstance::GetThisSideData() {
    return *(int*)((char*)this + 0x28);
}
