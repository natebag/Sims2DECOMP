// 0x802A83CC (92B) AptError::CleanNativeFunctions(void) — MI-vcall slot 2 on g_AptRegistry

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* name, const char* other, int val) = 0;
};

extern AptRegistry* g_AptRegistry;

namespace AptError {
    void CleanNativeFunctions(void);
}

void AptError::CleanNativeFunctions(void) {
    AptRegistry* r = g_AptRegistry;
    if (r == 0) return;
    r->Register("AptError", "default", 1325);
    g_AptRegistry = 0;
}
