// 0x802A2B68 (1180B) AptMathObj::CleanNativeFunctions(void) - 18x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptMathObj_Reg1;
extern AptRegistry* g_AptMathObj_Reg2;
extern AptRegistry* g_AptMathObj_Reg3;
extern AptRegistry* g_AptMathObj_Reg4;
extern AptRegistry* g_AptMathObj_Reg5;
extern AptRegistry* g_AptMathObj_Reg6;
extern AptRegistry* g_AptMathObj_Reg7;
extern AptRegistry* g_AptMathObj_Reg8;
extern AptRegistry* g_AptMathObj_Reg9;
extern AptRegistry* g_AptMathObj_Reg10;
extern AptRegistry* g_AptMathObj_Reg11;
extern AptRegistry* g_AptMathObj_Reg12;
extern AptRegistry* g_AptMathObj_Reg13;
extern AptRegistry* g_AptMathObj_Reg14;
extern AptRegistry* g_AptMathObj_Reg15;
extern AptRegistry* g_AptMathObj_Reg16;
extern AptRegistry* g_AptMathObj_Reg17;
extern AptRegistry* g_AptMathObj_Reg18;

extern char s_AptMathObj_func[];
extern char s_AptMathObj_file[];

namespace AptMathObj {
    void CleanNativeFunctions(void) {
        if (g_AptMathObj_Reg1) { g_AptMathObj_Reg1->Register(s_AptMathObj_func, s_AptMathObj_file, 116); g_AptMathObj_Reg1 = 0; }
        if (g_AptMathObj_Reg2) { g_AptMathObj_Reg2->Register(s_AptMathObj_func, s_AptMathObj_file, 117); g_AptMathObj_Reg2 = 0; }
        if (g_AptMathObj_Reg3) { g_AptMathObj_Reg3->Register(s_AptMathObj_func, s_AptMathObj_file, 118); g_AptMathObj_Reg3 = 0; }
        if (g_AptMathObj_Reg4) { g_AptMathObj_Reg4->Register(s_AptMathObj_func, s_AptMathObj_file, 119); g_AptMathObj_Reg4 = 0; }
        if (g_AptMathObj_Reg5) { g_AptMathObj_Reg5->Register(s_AptMathObj_func, s_AptMathObj_file, 120); g_AptMathObj_Reg5 = 0; }
        if (g_AptMathObj_Reg6) { g_AptMathObj_Reg6->Register(s_AptMathObj_func, s_AptMathObj_file, 121); g_AptMathObj_Reg6 = 0; }
        if (g_AptMathObj_Reg7) { g_AptMathObj_Reg7->Register(s_AptMathObj_func, s_AptMathObj_file, 123); g_AptMathObj_Reg7 = 0; }
        if (g_AptMathObj_Reg8) { g_AptMathObj_Reg8->Register(s_AptMathObj_func, s_AptMathObj_file, 124); g_AptMathObj_Reg8 = 0; }
        if (g_AptMathObj_Reg9) { g_AptMathObj_Reg9->Register(s_AptMathObj_func, s_AptMathObj_file, 125); g_AptMathObj_Reg9 = 0; }
        if (g_AptMathObj_Reg10) { g_AptMathObj_Reg10->Register(s_AptMathObj_func, s_AptMathObj_file, 126); g_AptMathObj_Reg10 = 0; }
        if (g_AptMathObj_Reg11) { g_AptMathObj_Reg11->Register(s_AptMathObj_func, s_AptMathObj_file, 127); g_AptMathObj_Reg11 = 0; }
        if (g_AptMathObj_Reg12) { g_AptMathObj_Reg12->Register(s_AptMathObj_func, s_AptMathObj_file, 128); g_AptMathObj_Reg12 = 0; }
        if (g_AptMathObj_Reg13) { g_AptMathObj_Reg13->Register(s_AptMathObj_func, s_AptMathObj_file, 129); g_AptMathObj_Reg13 = 0; }
        if (g_AptMathObj_Reg14) { g_AptMathObj_Reg14->Register(s_AptMathObj_func, s_AptMathObj_file, 130); g_AptMathObj_Reg14 = 0; }
        if (g_AptMathObj_Reg15) { g_AptMathObj_Reg15->Register(s_AptMathObj_func, s_AptMathObj_file, 131); g_AptMathObj_Reg15 = 0; }
        if (g_AptMathObj_Reg16) { g_AptMathObj_Reg16->Register(s_AptMathObj_func, s_AptMathObj_file, 132); g_AptMathObj_Reg16 = 0; }
        if (g_AptMathObj_Reg17) { g_AptMathObj_Reg17->Register(s_AptMathObj_func, s_AptMathObj_file, 133); g_AptMathObj_Reg17 = 0; }
        if (g_AptMathObj_Reg18) { g_AptMathObj_Reg18->Register(s_AptMathObj_func, s_AptMathObj_file, 134); g_AptMathObj_Reg18 = 0; }
    }
}
