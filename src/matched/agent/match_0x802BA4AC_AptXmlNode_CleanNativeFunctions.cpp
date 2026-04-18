// 0x802BA4AC (412B) AptXmlNode::CleanNativeFunctions(void) — 6x AptRegistry Register (ids 118-123)

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptXmlNode_Reg1;
extern AptRegistry* g_AptXmlNode_Reg2;
extern AptRegistry* g_AptXmlNode_Reg3;
extern AptRegistry* g_AptXmlNode_Reg4;
extern AptRegistry* g_AptXmlNode_Reg5;
extern AptRegistry* g_AptXmlNode_Reg6;

extern char s_AptXmlNode_func[];
extern char s_AptXmlNode_file[];

namespace AptXmlNode {
    void CleanNativeFunctions(void) {
        if (g_AptXmlNode_Reg1) { g_AptXmlNode_Reg1->Register(s_AptXmlNode_func, s_AptXmlNode_file, 118); g_AptXmlNode_Reg1 = 0; }
        if (g_AptXmlNode_Reg2) { g_AptXmlNode_Reg2->Register(s_AptXmlNode_func, s_AptXmlNode_file, 119); g_AptXmlNode_Reg2 = 0; }
        if (g_AptXmlNode_Reg3) { g_AptXmlNode_Reg3->Register(s_AptXmlNode_func, s_AptXmlNode_file, 120); g_AptXmlNode_Reg3 = 0; }
        if (g_AptXmlNode_Reg4) { g_AptXmlNode_Reg4->Register(s_AptXmlNode_func, s_AptXmlNode_file, 121); g_AptXmlNode_Reg4 = 0; }
        if (g_AptXmlNode_Reg5) { g_AptXmlNode_Reg5->Register(s_AptXmlNode_func, s_AptXmlNode_file, 122); g_AptXmlNode_Reg5 = 0; }
        if (g_AptXmlNode_Reg6) { g_AptXmlNode_Reg6->Register(s_AptXmlNode_func, s_AptXmlNode_file, 123); g_AptXmlNode_Reg6 = 0; }
    }
}
