// 0x80285B10 (732B) AptArray::CleanNativeFunctions(void) - 11x AptRegistry Register (ids 95-105)

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptArray_Reg1;
extern AptRegistry* g_AptArray_Reg2;
extern AptRegistry* g_AptArray_Reg3;
extern AptRegistry* g_AptArray_Reg4;
extern AptRegistry* g_AptArray_Reg5;
extern AptRegistry* g_AptArray_Reg6;
extern AptRegistry* g_AptArray_Reg7;
extern AptRegistry* g_AptArray_Reg8;
extern AptRegistry* g_AptArray_Reg9;
extern AptRegistry* g_AptArray_Reg10;
extern AptRegistry* g_AptArray_Reg11;

extern char s_AptArray_func[];
extern char s_AptArray_file[];

namespace AptArray {
    void CleanNativeFunctions(void) {
        if (g_AptArray_Reg1) { g_AptArray_Reg1->Register(s_AptArray_func, s_AptArray_file, 95); g_AptArray_Reg1 = 0; }
        if (g_AptArray_Reg2) { g_AptArray_Reg2->Register(s_AptArray_func, s_AptArray_file, 96); g_AptArray_Reg2 = 0; }
        if (g_AptArray_Reg3) { g_AptArray_Reg3->Register(s_AptArray_func, s_AptArray_file, 97); g_AptArray_Reg3 = 0; }
        if (g_AptArray_Reg4) { g_AptArray_Reg4->Register(s_AptArray_func, s_AptArray_file, 98); g_AptArray_Reg4 = 0; }
        if (g_AptArray_Reg5) { g_AptArray_Reg5->Register(s_AptArray_func, s_AptArray_file, 99); g_AptArray_Reg5 = 0; }
        if (g_AptArray_Reg6) { g_AptArray_Reg6->Register(s_AptArray_func, s_AptArray_file, 100); g_AptArray_Reg6 = 0; }
        if (g_AptArray_Reg7) { g_AptArray_Reg7->Register(s_AptArray_func, s_AptArray_file, 101); g_AptArray_Reg7 = 0; }
        if (g_AptArray_Reg8) { g_AptArray_Reg8->Register(s_AptArray_func, s_AptArray_file, 102); g_AptArray_Reg8 = 0; }
        if (g_AptArray_Reg9) { g_AptArray_Reg9->Register(s_AptArray_func, s_AptArray_file, 103); g_AptArray_Reg9 = 0; }
        if (g_AptArray_Reg10) { g_AptArray_Reg10->Register(s_AptArray_func, s_AptArray_file, 104); g_AptArray_Reg10 = 0; }
        if (g_AptArray_Reg11) { g_AptArray_Reg11->Register(s_AptArray_func, s_AptArray_file, 105); g_AptArray_Reg11 = 0; }
    }
}

