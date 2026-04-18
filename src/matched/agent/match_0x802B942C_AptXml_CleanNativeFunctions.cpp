// 0x802B942C (284B) AptXml::CleanNativeFunctions(void) — 4x AptRegistry Register (ids 81,82,84,85)

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptXml_Reg1;
extern AptRegistry* g_AptXml_Reg2;
extern AptRegistry* g_AptXml_Reg3;
extern AptRegistry* g_AptXml_Reg4;

extern char s_AptXml_func[];
extern char s_AptXml_file[];

namespace AptXml {
    void CleanNativeFunctions(void) {
        if (g_AptXml_Reg1) {
            g_AptXml_Reg1->Register(s_AptXml_func, s_AptXml_file, 81);
            g_AptXml_Reg1 = 0;
        }
        if (g_AptXml_Reg2) {
            g_AptXml_Reg2->Register(s_AptXml_func, s_AptXml_file, 82);
            g_AptXml_Reg2 = 0;
        }
        if (g_AptXml_Reg3) {
            g_AptXml_Reg3->Register(s_AptXml_func, s_AptXml_file, 84);
            g_AptXml_Reg3 = 0;
        }
        if (g_AptXml_Reg4) {
            g_AptXml_Reg4->Register(s_AptXml_func, s_AptXml_file, 85);
            g_AptXml_Reg4 = 0;
        }
    }
}
