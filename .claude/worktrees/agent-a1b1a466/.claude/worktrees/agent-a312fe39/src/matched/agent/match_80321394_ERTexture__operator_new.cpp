// 0x80321394 (8 bytes) - ERTexture::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERTexture(size_t size, void* ptr) {
    return ptr;
}
