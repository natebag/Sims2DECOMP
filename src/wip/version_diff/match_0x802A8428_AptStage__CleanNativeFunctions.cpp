// 0x802A8428 (156B) AptStage::CleanNativeFunctions(void) — MI-vcall 2x Register calls
// STATUS: template-rip-near-miss (S11 Audit #4)
// SIZE_MISMATCH vs 156B DOL. AptRegistry template proven on sibling commits
// a76573f7/a9275590/f64ea121/faf1592b. Likely off by 1-2 Register() calls or
// a final stack-fixup diff. Revisit after MI-vcall pivot if token budget allows.

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* name, const char* other, int val) = 0;
};

extern AptRegistry* g_AptRegistry;
extern AptRegistry* g_AptRegistry2;

namespace AptStage {
    void CleanNativeFunctions(void);
}

void AptStage::CleanNativeFunctions(void) {
    AptRegistry* r = g_AptRegistry;
    if (r == 0) return;
    r->Register("AptStage", "default", 1356);

    r = g_AptRegistry2;
    if (r == 0) return;
    r->Register("AptStage", "default", 1357);
}
