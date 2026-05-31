// FLAGS: -fno-schedule-insns
// 0x800F99CC ObjectModuleImpl::GetNumPortals(void) (20B)
// lwz r0,0x2068(r3); lwz r3,0x206c(r3); subf r3,r0,r3; srawi r3,r3,2; blr
// TArray<Portal*> size: (end - begin) element count
struct ObjectModuleImpl {
    char pad[0x2068];
    void** m_portalsBegin;  // 0x2068
    void** m_portalsEnd;    // 0x206C
    int GetNumPortals();
};

int ObjectModuleImpl::GetNumPortals() {
    void** begin = m_portalsBegin;
    void** end = m_portalsEnd;
    return end - begin;
}
