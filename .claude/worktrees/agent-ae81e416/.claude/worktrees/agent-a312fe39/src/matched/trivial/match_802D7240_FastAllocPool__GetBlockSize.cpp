// 0x802D7240 (8 bytes)
class FastAllocPool {
public:
    int GetBlockSize();
};

int FastAllocPool::GetBlockSize() {
    return *(int*)((char*)this + 0xC);
}
