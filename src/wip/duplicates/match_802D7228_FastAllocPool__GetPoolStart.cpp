// 0x802D7228 (8 bytes)
class FastAllocPool {
public:
    int GetPoolStart();
};

int FastAllocPool::GetPoolStart() {
    return *(int*)((char*)this + 0x0);
}
