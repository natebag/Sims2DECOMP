// 0x80030814 (8 bytes) — mr r3, r4; blr
// Placement new: returns the provided pointer

class EIFenceWall {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIFenceWall::operator new(unsigned int size, void* ptr) {
    return ptr;
}
