typedef unsigned int size_t;

void* GetAllocGroup(void);
void* HeapAlloc(void* group, size_t size, int align, int param3, int param4);
void MemClear(void* ptr, int param, size_t size);

struct ISimInstance {
    static void* operator new(size_t size);
};

void* ISimInstance::operator new(size_t size) {
    void* group = GetAllocGroup();
    void* ptr = HeapAlloc(group, size, 16, 0, 0);
    MemClear(ptr, 0, size);
    return ptr;
}
