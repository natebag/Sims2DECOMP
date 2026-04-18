// 0x802AB8D4 (220B) AptSound::CleanNativeFunctions(void) — 3x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptSound_Reg1;
extern AptRegistry* g_AptSound_Reg2;
extern AptRegistry* g_AptSound_Reg3;

extern char s_AptSound_func[];
extern char s_AptSound_file[];

namespace AptSound {
    void CleanNativeFunctions(void) {
        if (g_AptSound_Reg1) {
            g_AptSound_Reg1->Register(s_AptSound_func, s_AptSound_file, 57);
            g_AptSound_Reg1 = 0;
        }
        if (g_AptSound_Reg2) {
            g_AptSound_Reg2->Register(s_AptSound_func, s_AptSound_file, 58);
            g_AptSound_Reg2 = 0;
        }
        if (g_AptSound_Reg3) {
            g_AptSound_Reg3->Register(s_AptSound_func, s_AptSound_file, 59);
            g_AptSound_Reg3 = 0;
        }
    }
}
