struct EAHeap;
struct EAllocGroup {
    char _pad[0x0c];
    EAHeap *m_allocHeap;
    void SetAllocHeap(EAHeap *val);
};
void EAllocGroup::SetAllocHeap(EAHeap *val) { m_allocHeap = val; }
