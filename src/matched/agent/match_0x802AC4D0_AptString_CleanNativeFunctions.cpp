// 0x802AC4D0 (796B) AptString::CleanNativeFunctions(void) - 12x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptString_Reg1;
extern AptRegistry* g_AptString_Reg2;
extern AptRegistry* g_AptString_Reg3;
extern AptRegistry* g_AptString_Reg4;
extern AptRegistry* g_AptString_Reg5;
extern AptRegistry* g_AptString_Reg6;
extern AptRegistry* g_AptString_Reg7;
extern AptRegistry* g_AptString_Reg8;
extern AptRegistry* g_AptString_Reg9;
extern AptRegistry* g_AptString_Reg10;
extern AptRegistry* g_AptString_Reg11;
extern AptRegistry* g_AptString_Reg12;

extern char s_AptString_func[];
extern char s_AptString_file[];

namespace AptString {
    void CleanNativeFunctions(void) {
        if (g_AptString_Reg1) { g_AptString_Reg1->Register(s_AptString_func, s_AptString_file, 155); g_AptString_Reg1 = 0; }
        if (g_AptString_Reg2) { g_AptString_Reg2->Register(s_AptString_func, s_AptString_file, 156); g_AptString_Reg2 = 0; }
        if (g_AptString_Reg3) { g_AptString_Reg3->Register(s_AptString_func, s_AptString_file, 157); g_AptString_Reg3 = 0; }
        if (g_AptString_Reg4) { g_AptString_Reg4->Register(s_AptString_func, s_AptString_file, 158); g_AptString_Reg4 = 0; }
        if (g_AptString_Reg5) { g_AptString_Reg5->Register(s_AptString_func, s_AptString_file, 159); g_AptString_Reg5 = 0; }
        if (g_AptString_Reg6) { g_AptString_Reg6->Register(s_AptString_func, s_AptString_file, 160); g_AptString_Reg6 = 0; }
        if (g_AptString_Reg7) { g_AptString_Reg7->Register(s_AptString_func, s_AptString_file, 161); g_AptString_Reg7 = 0; }
        if (g_AptString_Reg8) { g_AptString_Reg8->Register(s_AptString_func, s_AptString_file, 162); g_AptString_Reg8 = 0; }
        if (g_AptString_Reg9) { g_AptString_Reg9->Register(s_AptString_func, s_AptString_file, 163); g_AptString_Reg9 = 0; }
        if (g_AptString_Reg10) { g_AptString_Reg10->Register(s_AptString_func, s_AptString_file, 164); g_AptString_Reg10 = 0; }
        if (g_AptString_Reg11) { g_AptString_Reg11->Register(s_AptString_func, s_AptString_file, 165); g_AptString_Reg11 = 0; }
        if (g_AptString_Reg12) { g_AptString_Reg12->Register(s_AptString_func, s_AptString_file, 166); g_AptString_Reg12 = 0; }
    }
}
