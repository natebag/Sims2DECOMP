// 0x8030683C EFrameAllocGroup::Alloc (48B)
struct EAllocGroup;
extern "C" void* EAllocGroup_Alloc(EAllocGroup*, unsigned int size, int align);

struct EFrameAllocGroup {
    char pad[0x04];
    char m_groups[0x30];
    int m_index;

    void* Alloc(unsigned int size, int align);
};

void* EFrameAllocGroup::Alloc(unsigned int size, int align) {
    return EAllocGroup_Alloc((EAllocGroup*)(m_groups + m_index * 24), size, align);
}
