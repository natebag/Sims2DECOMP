// 0x802D7248 (8 bytes)
class FastAllocPool {
public:
    int GetPoolBlocks();
};

int FastAllocPool::GetPoolBlocks() {
    return *(int*)((char*)this + 0x8);
}
