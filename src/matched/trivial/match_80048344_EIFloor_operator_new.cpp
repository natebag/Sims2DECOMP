// 0x80048344 (8 bytes)
class EIFloor {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIFloor::operator new(unsigned int size, void* ptr) {
    return ptr;
}
