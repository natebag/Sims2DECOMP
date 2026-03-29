// 0x8036C2D4 (8 bytes)
class RParticle {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* RParticle::operator new(unsigned int size, void* ptr) {
    return ptr;
}
