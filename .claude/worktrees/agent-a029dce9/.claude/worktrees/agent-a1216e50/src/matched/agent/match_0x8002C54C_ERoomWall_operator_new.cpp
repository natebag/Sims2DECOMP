typedef unsigned int size_t;

void* GetAllocGroup(void);
void* HeapAllocAligned(void* group, int align, int param);
void MemClear(void* ptr, int param, size_t size);

struct ERoomWall {
    static void* operator new(size_t size);
};

void* ERoomWall::operator new(size_t size) {
    void* group = GetAllocGroup();
    void* ptr = HeapAllocAligned(group, 64, 0);
    MemClear(ptr, 0, size);
    return ptr;
}
