// 0x802381E0 (8 bytes)
class ERLevel {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERLevel::operator new(unsigned int size, void* ptr) {
    return ptr;
}
