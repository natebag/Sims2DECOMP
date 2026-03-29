// 0x8003061C (8 bytes)
class EIWallPart {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIWallPart::operator new(unsigned int size, void* ptr) {
    return ptr;
}
