// 0x802D7220 (8 bytes)
class FastAllocPool {
public:
    int GetAlignment();
};

int FastAllocPool::GetAlignment() {
    return *(int*)((char*)this + 0x10);
}
