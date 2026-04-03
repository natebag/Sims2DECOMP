// 0x802295F8 (8 bytes)
class EInstance {
public:
    int GetOtherSideFn();
};

int EInstance::GetOtherSideFn() {
    return *(int*)((char*)this + 0x20);
}
