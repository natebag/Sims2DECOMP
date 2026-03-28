// 0x8003061C (8 bytes) — mr r3, r4; blr
// Placement new: returns the provided pointer

class EIWallPart {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EIWallPart::operator new(unsigned int size, void* ptr) {
    return ptr;
}
