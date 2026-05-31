// FLAGS: -fno-schedule-insns
// 0x800F99A8 ObjectModuleImpl::GetNumPeople(void) (20B)
// lwz r0,0x2058(r3); lwz r3,0x205c(r3); subf r3,r0,r3; srawi r3,r3,2; blr
// TArray<People*> size: (end - begin) element count
struct ObjectModuleImpl {
    char pad[0x2058];
    void** m_peopleBegin;   // 0x2058
    void** m_peopleEnd;     // 0x205C
    int GetNumPeople();
};

int ObjectModuleImpl::GetNumPeople() {
    void** begin = m_peopleBegin;
    void** end = m_peopleEnd;
    return end - begin;
}
