struct EAllocGroup;
extern "C" void* EAllocGroup_Alloc(EAllocGroup*, unsigned int size, int align);

struct EFrameAllocGroup {
    char pad[0x34];
    int m_index;
};

void* EFrameAllocGroup_Alloc(EFrameAllocGroup* self, unsigned int size, int align) {
    return EAllocGroup_Alloc((EAllocGroup*)((char*)self + self->m_index * 24 + 4), size, align);
}
