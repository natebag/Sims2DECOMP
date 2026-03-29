// 0x80317944 (8 bytes)
class ERFont {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERFont::operator new(unsigned int size, void* ptr) {
    return ptr;
}
