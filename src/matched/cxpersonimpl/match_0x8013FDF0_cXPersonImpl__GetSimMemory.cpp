// 0x8013FDF0 cXPersonImpl::GetSimMemory(cXPerson*, int) (148B)
// Pattern: get self-id from m_subPtr.vt[0x1B0/0x1B4](), get other-id from
// other.vt-at-+4[0x1B0/0x1B4](), then call SimMemoryRouter at
// m_implPtr->slot_0x58 (vt-at-0)[0x1B0/0x1B4](self_id, other_id, memType).
//
// Family: shares shape with SetSimMemory (0x8013FE84) and GetDominantMemory
// (0x8013FF20) — differ only in third-call slot offset and arg count.

typedef int (*FnId)(void*);
typedef void* (*FnLookup)(void*, int, int, int);

struct cXPerson_SimMemory {
    char* m_implPtr;   // 0x0
    char* m_subPtr;    // 0x4
    void* GetSimMemory(void* otherPerson, int memType);
};

void* cXPerson_SimMemory::GetSimMemory(void* otherPerson, int memType) {
    char* sub = m_subPtr;
    char* vt1 = *(char**)(sub + 4);
    short adj1 = *(short*)(vt1 + 0x1B0);
    FnId fn1 = (FnId)*(void**)(vt1 + 0x1B4);
    int self_id = fn1(sub + adj1);

    char* op = (char*)otherPerson;
    char* vt2 = *(char**)(op + 4);
    short adj2 = *(short*)(vt2 + 0x1B0);
    FnId fn2 = (FnId)*(void**)(vt2 + 0x1B4);
    int other_id = fn2(op + adj2);

    char* router = *(char**)(m_implPtr + 0x58);
    char* vt3 = *(char**)(router + 0);
    short adj3 = *(short*)(vt3 + 0x1B0);
    FnLookup fn3 = (FnLookup)*(void**)(vt3 + 0x1B4);
    return fn3(router + adj3, self_id, other_id, memType);
}
