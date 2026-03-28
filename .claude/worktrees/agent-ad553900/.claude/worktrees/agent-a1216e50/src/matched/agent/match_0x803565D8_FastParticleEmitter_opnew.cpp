/* FastParticleEmitter::operator new(unsigned int) - 0x803565D8 (64 bytes) */

struct EAHeap {
    void *MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap *MainHeap();

struct FastParticleEmitter {
    void *operator new(unsigned int size);
};

void *FastParticleEmitter::operator new(unsigned int size)
{
    EAHeap *heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
