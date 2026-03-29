// 0x80313E08 (8 bytes)
class ERFlash {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERFlash::operator new(unsigned int size, void* ptr) {
    return ptr;
}
