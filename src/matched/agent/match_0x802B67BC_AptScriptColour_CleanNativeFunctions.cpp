// 0x802B67BC (284B) AptScriptColour::CleanNativeFunctions(void) — 4x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptScriptColour_Reg1;
extern AptRegistry* g_AptScriptColour_Reg2;
extern AptRegistry* g_AptScriptColour_Reg3;
extern AptRegistry* g_AptScriptColour_Reg4;

extern char s_AptScriptColour_func[];
extern char s_AptScriptColour_file[];

namespace AptScriptColour {
    void CleanNativeFunctions(void) {
        if (g_AptScriptColour_Reg1) {
            g_AptScriptColour_Reg1->Register(s_AptScriptColour_func, s_AptScriptColour_file, 112);
            g_AptScriptColour_Reg1 = 0;
        }
        if (g_AptScriptColour_Reg2) {
            g_AptScriptColour_Reg2->Register(s_AptScriptColour_func, s_AptScriptColour_file, 113);
            g_AptScriptColour_Reg2 = 0;
        }
        if (g_AptScriptColour_Reg3) {
            g_AptScriptColour_Reg3->Register(s_AptScriptColour_func, s_AptScriptColour_file, 114);
            g_AptScriptColour_Reg3 = 0;
        }
        if (g_AptScriptColour_Reg4) {
            g_AptScriptColour_Reg4->Register(s_AptScriptColour_func, s_AptScriptColour_file, 115);
            g_AptScriptColour_Reg4 = 0;
        }
    }
}
