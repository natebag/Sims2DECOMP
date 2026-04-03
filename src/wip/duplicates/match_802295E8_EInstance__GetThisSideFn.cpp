// 0x802295E8 (8 bytes)
class EInstance {
public:
    int GetThisSideFn();
};

int EInstance::GetThisSideFn() {
    return *(int*)((char*)this + 0x1C);
}
