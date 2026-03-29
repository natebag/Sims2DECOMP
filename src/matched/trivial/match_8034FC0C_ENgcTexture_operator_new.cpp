// 0x8034FC0C (8 bytes)
class ENgcTexture {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ENgcTexture::operator new(unsigned int size, void* ptr) {
    return ptr;
}
