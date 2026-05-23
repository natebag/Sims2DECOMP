// 0x8013FE84 cXPersonImpl::SetSimMemory(cXPerson*, int, int) (156B)
// Sibling of GetSimMemory (0x8013FDF0). One extra arg (arg4 passed as r7),
// and third dispatch uses slot 0x1B8/0x1BC (vs GetSimMemory's 0x1B0/0x1B4)
// on the SimMemoryRouter at m_implPtr->slot_0x58.

typedef int (*FnId)(void*);
typedef void* (*FnSet)(void*, int, int, int, int);

struct cXPerson_SetMem {
    char* m_implPtr;   // 0x0
    char* m_subPtr;    // 0x4
    void* SetSimMemory(void* otherPerson, int arg3, int arg4);
};

void* cXPerson_SetMem::SetSimMemory(void* otherPerson, int arg3, int arg4) {
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
    short adj3 = *(short*)(vt3 + 0x1B8);
    FnSet fn3 = (FnSet)*(void**)(vt3 + 0x1BC);
    return fn3(router + adj3, self_id, other_id, arg3, arg4);
}
