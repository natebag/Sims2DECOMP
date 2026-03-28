// 0x802295F0 (8 bytes)
class EInstance {
public:
    int GetOtherSideData();
};

int EInstance::GetOtherSideData() {
    return *(int*)((char*)this + 0x24);
}
