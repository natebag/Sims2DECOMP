// 0x80285B10 (92B) AptActionInterpreter::CleanNativeFunctions(void) — MI-vcall slot 2
// STATUS: wrong-class-misattribution (S11 Audit #4) — REWRITE REQUIRED
// 0x80285B10 in u2_ngc_release_dvd.map is AptArray::CleanNativeFunctions (732B),
// NOT AptActionInterpreter (this file's body is 92B). Parked pending rewrite against
// the true AptArray 732B target. When resurrecting: rename file, rewrite against
// AptArray class, verify size 732B from map.

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* name, const char* other, int val) = 0;
};

extern AptRegistry* g_AptRegistry;
extern char g_str_AptActionInterpreter[] __attribute__((section(".rodata")));
extern char g_str_default[] __attribute__((section(".rodata")));

namespace AptActionInterpreter {
    void CleanNativeFunctions(void);
}

void AptActionInterpreter::CleanNativeFunctions(void) {
    AptRegistry* r = g_AptRegistry;
    if (r == 0) return;
    r->Register(g_str_AptActionInterpreter, g_str_default, 95);
    g_AptRegistry = 0;
}
