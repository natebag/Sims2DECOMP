// 0x802A6E20 (412B) AptLoadVars::CleanNativeFunctions(void) — 6x AptRegistry Register (ids 1095-1100)

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptLoadVars_Reg1;
extern AptRegistry* g_AptLoadVars_Reg2;
extern AptRegistry* g_AptLoadVars_Reg3;
extern AptRegistry* g_AptLoadVars_Reg4;
extern AptRegistry* g_AptLoadVars_Reg5;
extern AptRegistry* g_AptLoadVars_Reg6;

extern char s_AptLoadVars_func[];
extern char s_AptLoadVars_file[];

namespace AptLoadVars {
    void CleanNativeFunctions(void) {
        if (g_AptLoadVars_Reg1) { g_AptLoadVars_Reg1->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1095); g_AptLoadVars_Reg1 = 0; }
        if (g_AptLoadVars_Reg2) { g_AptLoadVars_Reg2->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1096); g_AptLoadVars_Reg2 = 0; }
        if (g_AptLoadVars_Reg3) { g_AptLoadVars_Reg3->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1097); g_AptLoadVars_Reg3 = 0; }
        if (g_AptLoadVars_Reg4) { g_AptLoadVars_Reg4->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1098); g_AptLoadVars_Reg4 = 0; }
        if (g_AptLoadVars_Reg5) { g_AptLoadVars_Reg5->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1099); g_AptLoadVars_Reg5 = 0; }
        if (g_AptLoadVars_Reg6) { g_AptLoadVars_Reg6->Register(s_AptLoadVars_func, s_AptLoadVars_file, 1100); g_AptLoadVars_Reg6 = 0; }
    }
}
