typedef unsigned int size_t;

void* GetAllocGroup(void);
void* HeapAlloc(void* group, size_t size, int align, int param3, int param4);

struct ERTQuantize4D {
    static void* operator new(size_t size);
};

void* ERTQuantize4D::operator new(size_t size) {
    void* group = GetAllocGroup();
    return HeapAlloc(group, size, 16, 0, 0);
}
