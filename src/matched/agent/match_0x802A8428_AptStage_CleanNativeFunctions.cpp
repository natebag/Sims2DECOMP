// 0x802A8428 (156B) AptStage::CleanNativeFunctions(void) - 2x AptRegistry Register (ids 1356, 1357)

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptStage_Reg1;
extern AptRegistry* g_AptStage_Reg2;

extern char s_AptStage_func[];
extern char s_AptStage_file[];

namespace AptStage {
    void CleanNativeFunctions(void) {
        if (g_AptStage_Reg1) { g_AptStage_Reg1->Register(s_AptStage_func, s_AptStage_file, 1356); g_AptStage_Reg1 = 0; }
        if (g_AptStage_Reg2) { g_AptStage_Reg2->Register(s_AptStage_func, s_AptStage_file, 1357); g_AptStage_Reg2 = 0; }
    }
}
