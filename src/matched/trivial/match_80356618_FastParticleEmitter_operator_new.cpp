// 0x80356618 (8 bytes)
namespace Effects {
class FastParticleEmitter {
public:
    void* operator new(unsigned int size, void* ptr);
};
}

void* Effects::FastParticleEmitter::operator new(unsigned int size, void* ptr) {
    return ptr;
}
