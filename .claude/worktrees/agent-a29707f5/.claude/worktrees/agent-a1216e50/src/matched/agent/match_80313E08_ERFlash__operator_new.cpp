// 0x80313E08 (8 bytes) - ERFlash::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERFlash(size_t size, void* ptr) {
    return ptr;
}
