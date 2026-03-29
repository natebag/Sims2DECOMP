// 0x80321394 (8 bytes)
class ERTexture {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERTexture::operator new(unsigned int size, void* ptr) {
    return ptr;
}
