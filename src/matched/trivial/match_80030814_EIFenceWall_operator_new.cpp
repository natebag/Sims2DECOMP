// 0x80030814 (8 bytes)
class EIFenceWall {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIFenceWall::operator new(unsigned int size, void* ptr) {
    return ptr;
}
