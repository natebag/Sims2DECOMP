// 0x80317944 (8 bytes) - ERFont::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERFont(size_t size, void* ptr) {
    return ptr;
}
