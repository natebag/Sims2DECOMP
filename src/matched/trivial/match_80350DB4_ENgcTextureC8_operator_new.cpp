// 0x80350DB4 (8 bytes)
class ENgcTextureC8 {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ENgcTextureC8::operator new(unsigned int size, void* ptr) {
    return ptr;
}
