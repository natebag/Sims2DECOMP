// 0x80311DC8 EResource::EResource(void) (48B)
//
// Standalone EResource ctor (NOT inlined fragment despite earlier S15 design
// doc claim). 5 stores: m_12=1 (short), m_0=vt, m_14=0 (short), m_16=128,
// m_4=0.
//
// Recipe: 3 swap_adj for prologue/store reorder. No gpr_relabel needed —
// raw cc1plus output already has `mr r11, r3` matching DOL's this-alias
// choice. The reorder fixes lis/sth, la/li, stw/li adjacent-pair sequencing.
//
// ASMPROC_swap_adj: a=lis b=sth which=first
// ASMPROC_swap_adj: a=la b=li which=first
// ASMPROC_swap_adj: a=stw b=li which=first

extern char EResource_vt[];

class EResource {
public:
    void* m_0;
    int   m_4;
    char  _8[4];
    short m_12;
    short m_14;
    int   m_16;
    EResource();
};

EResource::EResource() {
    int zero = 0;
    *(volatile short*)((char*)this + 12) = 1;
    *(volatile int*)((char*)this + 0) = (int)EResource_vt;
    *(volatile short*)((char*)this + 14) = (short)zero;
    *(volatile int*)((char*)this + 16) = 128;
    *(volatile int*)((char*)this + 4) = zero;
}
