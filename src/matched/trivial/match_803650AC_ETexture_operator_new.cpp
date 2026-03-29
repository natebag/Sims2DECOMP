// 0x803650AC (8 bytes)
class ETexture {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ETexture::operator new(unsigned int size, void* ptr) {
    return ptr;
}
