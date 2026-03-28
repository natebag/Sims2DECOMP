// 0x802A9880 (8 bytes)
class AptAnimationPoolData {
public:
    int GetActionPool();
};

int AptAnimationPoolData::GetActionPool() {
    return *(int*)((char*)this + 0x98);
}
