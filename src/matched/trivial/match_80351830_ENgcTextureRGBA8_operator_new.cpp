// 0x80351830 (8 bytes)
class ENgcTextureRGBA8 {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ENgcTextureRGBA8::operator new(unsigned int size, void* ptr) {
    return ptr;
}
