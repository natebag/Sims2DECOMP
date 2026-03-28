// 0x8034FC0C (8 bytes) - ENgcTexture::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ENgcTexture(size_t size, void* ptr) {
    return ptr;
}
