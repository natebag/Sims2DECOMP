// 0x80368D30 (8 bytes)
class ERCharacter {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* ERCharacter::operator new(unsigned int size, void* ptr) {
    return ptr;
}
