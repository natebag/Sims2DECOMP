// 0x803650AC (8 bytes) - ETexture::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ETexture(size_t size, void* ptr) {
    return ptr;
}
