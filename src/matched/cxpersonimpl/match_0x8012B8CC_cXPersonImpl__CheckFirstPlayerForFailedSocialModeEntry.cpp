// 0x8012B8CC cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry (172B)
// Guard via slot 0xF0/0xF4 on m_subPtr.vt — if non-zero, early-return.
// Else issue three sequential calls:
//   1. slot 0x338/0x33C on m_subPtr.vt (sub_adj, 0)
//   2. slot 0x140/0x144 on m_subPtr.vt (sub_adj, 40, 0)
//   3. slot 0x138/0x13C on m_simulator (this+0x3F4), vt-at-0 layout (sim_adj)
//
// 0x3F4 read = m_simulator (TypeArch v4). Third dispatch reads m_simulator's
// vt at OFFSET 0 (not +4), so cSimulator/cSimulatorImpl's wrapper layout puts
// its vtable directly at +0 (single-inheritance shape — supports the SI-not-MI
// hypothesis).
//
// Posted as evidence for `cXPersonImpl_0x3F4_vtable_evidence`.

typedef int  (*FnGuard)(void*);
typedef void (*FnA)(void*, int);
typedef void (*FnB)(void*, int, int);
typedef void (*FnC)(void*);

struct cXPerson_CFPF {
    char pad0[4];
    char* m_subPtr;   // 0x4
    void CheckFirstPlayerForFailedSocialModeEntry();
};

void cXPerson_CFPF::CheckFirstPlayerForFailedSocialModeEntry() {
    char* sub0 = m_subPtr;
    char* vt0 = *(char**)(sub0 + 4);
    short adj0 = *(short*)(vt0 + 0xF0);
    FnGuard guard = (FnGuard)*(void**)(vt0 + 0xF4);
    if (guard(sub0 + adj0) != 0) return;

    char* sub1 = m_subPtr;
    char* vt1 = *(char**)(sub1 + 4);
    short adj1 = *(short*)(vt1 + 0x338);
    FnA fnA = (FnA)*(void**)(vt1 + 0x33C);
    fnA(sub1 + adj1, 0);

    char* sub2 = m_subPtr;
    char* vt2 = *(char**)(sub2 + 4);
    short adj2 = *(short*)(vt2 + 0x140);
    FnB fnB = (FnB)*(void**)(vt2 + 0x144);
    fnB(sub2 + adj2, 40, 0);

    char* sim = *(char**)((char*)this + 0x3F4);
    char* simvt = *(char**)(sim + 0);
    short adj3 = *(short*)(simvt + 0x138);
    FnC fnC = (FnC)*(void**)(simvt + 0x13C);
    fnC(sim + adj3);
}
