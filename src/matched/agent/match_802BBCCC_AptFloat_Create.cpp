// FLAGS: -fno-elide-constructors
// 0x802BBCCC AptFloat_Create (184B)
// DOL uses -32 stack frame; compiled uses -24. Adjust all frame offsets +8.
// ASMPROC_replace_insn: match="stwu 1,-24(1)" replacement="stwu 1,-32(1)"
// ASMPROC_replace_insn: match="stfd 31,16(1)" replacement="stfd 31,24(1)"
// ASMPROC_replace_insn: match="stmw 30,8(1)" replacement="stmw 30,16(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stw 0,36(1)"
// ASMPROC_replace_insn: match="lwz 0,28(1)" replacement="lwz 0,36(1)"
// ASMPROC_replace_insn: match="lmw 30,8(1)" replacement="lmw 30,16(1)"
// ASMPROC_replace_insn: match="lfd 31,16(1)" replacement="lfd 31,24(1)"
// ASMPROC_replace_insn: match="la 1,24(1)" replacement="la 1,32(1)"
typedef unsigned int uint;

struct DOGMA_PoolManager {
    void* Allocate(uint size);
};

struct AptAllocTracker {
    int m_max;
    int m_count;
    void** m_array;
};

struct AptFloatVal {
    uint m_flags;
    char _pad[4];
    void* m_vtable;
    float m_val;
};

extern AptFloatVal* AptFloat_spFirstFree;
extern DOGMA_PoolManager* spAptPoolManager;
extern AptAllocTracker* spAptAllocTracker;
extern int AptFloat_vtbl[];

void AptValue_ctor(void*, int);

AptFloatVal* AptFloat_Create(float val)
{
    AptFloatVal* p = AptFloat_spFirstFree;
    if (p != 0) {
        uint flags = p->m_flags;
        AptFloatVal* next = (AptFloatVal*)*(int*)&p->m_val;
        AptAllocTracker* t = spAptAllocTracker;
        uint nf = flags | 0x20000000;
        AptFloat_spFirstFree = next;
        p->m_flags = nf;
        int cnt = t->m_count;
        int mx = t->m_max;
        if (cnt >= mx) {
            p->m_flags = nf & ~0x20000000;
        } else {
            t->m_array[cnt] = (void*)p;
            t->m_count = cnt + 1;
        }
        p->m_val = val;
        return p;
    }
    AptFloatVal* q = (AptFloatVal*)spAptPoolManager->Allocate(16);
    AptValue_ctor(q, 6);
    q->m_val = val;
    q->m_vtable = (void*)AptFloat_vtbl;
    return q;
}
