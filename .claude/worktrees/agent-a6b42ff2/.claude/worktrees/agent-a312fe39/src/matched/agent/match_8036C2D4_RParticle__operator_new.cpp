// 0x8036C2D4 (8 bytes) - RParticle::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_RParticle(size_t size, void* ptr) {
    return ptr;
}
