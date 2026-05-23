// 0x8012B354 cXPersonImpl::IsPet (216B)
// Inlined IsDog || IsCat || IsMonkey. Same dispatch pattern as
// match_0x8012B1D4_cXPersonImpl__IsDog (slot 0x150/0x154 + slot 0x160/0x164),
// repeated for type-key values 2/3/4 (dog/cat/monkey).
//
// First dispatch (slot 0x150/0x154) is the non-Sim guard: returns 0 for
// non-Sim persons (animals/NPCs), non-zero for Sims. If Sim, early-return 0
// (a Sim is never a pet).

typedef int (*Fn1)(void*);
typedef void* (*Fn2)(void*);

struct cXPerson_IsPet {
    char pad_00[4];
    void* m_inner;
    int IsPet();
};

int cXPerson_IsPet::IsPet() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x150);
    Fn1 fn = (Fn1)*(void**)(vt + 0x154);
    int r1 = fn(inner + adj);
    if (r1 != 0) return 0;

    int isPet = 0;

    char* inner_a = (char*)m_inner;
    char* vt_a = *(char**)(inner_a + 4);
    short adj_a = *(short*)(vt_a + 0x160);
    Fn2 fn_a = (Fn2)*(void**)(vt_a + 0x164);
    void* p_a = fn_a(inner_a + adj_a);
    if (*(int*)((char*)p_a + 4) == 2) {
        isPet = 1;
    } else {
        char* inner_b = (char*)m_inner;
        char* vt_b = *(char**)(inner_b + 4);
        short adj_b = *(short*)(vt_b + 0x160);
        Fn2 fn_b = (Fn2)*(void**)(vt_b + 0x164);
        void* p_b = fn_b(inner_b + adj_b);
        if (*(int*)((char*)p_b + 4) == 3) {
            isPet = 1;
        } else {
            char* inner_c = (char*)m_inner;
            char* vt_c = *(char**)(inner_c + 4);
            short adj_c = *(short*)(vt_c + 0x160);
            Fn2 fn_c = (Fn2)*(void**)(vt_c + 0x164);
            void* p_c = fn_c(inner_c + adj_c);
            if (*(int*)((char*)p_c + 4) == 4) {
                isPet = 1;
            }
        }
    }
    return isPet;
}
