// 0x802A4EEC (540B) AptKey::CleanNativeFunctions(void) - 8x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptKey_Reg1;
extern AptRegistry* g_AptKey_Reg2;
extern AptRegistry* g_AptKey_Reg3;
extern AptRegistry* g_AptKey_Reg4;
extern AptRegistry* g_AptKey_Reg5;
extern AptRegistry* g_AptKey_Reg6;
extern AptRegistry* g_AptKey_Reg7;
extern AptRegistry* g_AptKey_Reg8;

extern char s_AptKey_func[];
extern char s_AptKey_file[];

namespace AptKey {
    void CleanNativeFunctions(void) {
        if (g_AptKey_Reg1) { g_AptKey_Reg1->Register(s_AptKey_func, s_AptKey_file, 424); g_AptKey_Reg1 = 0; }
        if (g_AptKey_Reg2) { g_AptKey_Reg2->Register(s_AptKey_func, s_AptKey_file, 425); g_AptKey_Reg2 = 0; }
        if (g_AptKey_Reg3) { g_AptKey_Reg3->Register(s_AptKey_func, s_AptKey_file, 426); g_AptKey_Reg3 = 0; }
        if (g_AptKey_Reg4) { g_AptKey_Reg4->Register(s_AptKey_func, s_AptKey_file, 427); g_AptKey_Reg4 = 0; }
        if (g_AptKey_Reg5) { g_AptKey_Reg5->Register(s_AptKey_func, s_AptKey_file, 428); g_AptKey_Reg5 = 0; }
        if (g_AptKey_Reg6) { g_AptKey_Reg6->Register(s_AptKey_func, s_AptKey_file, 429); g_AptKey_Reg6 = 0; }
        if (g_AptKey_Reg7) { g_AptKey_Reg7->Register(s_AptKey_func, s_AptKey_file, 430); g_AptKey_Reg7 = 0; }
        if (g_AptKey_Reg8) { g_AptKey_Reg8->Register(s_AptKey_func, s_AptKey_file, 431); g_AptKey_Reg8 = 0; }
    }
}
