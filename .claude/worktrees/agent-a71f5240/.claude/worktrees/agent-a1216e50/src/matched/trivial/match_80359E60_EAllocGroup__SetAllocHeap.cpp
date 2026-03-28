// 0x80359E60 (8 bytes)
class EAllocGroup {
public:
    void SetAllocHeap(int p);
};

void EAllocGroup::SetAllocHeap(int p) {
    *(int*)((char*)this + 0xC) = p;
}
