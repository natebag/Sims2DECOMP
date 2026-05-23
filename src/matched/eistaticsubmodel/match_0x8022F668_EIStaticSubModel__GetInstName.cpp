// 0x8022F668 (44B) EIStaticSubModel::GetInstName(EInstance::InstType &)
// li r0,4 | stw r0,0(r4) | lwz r9,0xA0(r3) | cmpwi r9,0 | bne +16
// lis/addi two static strings

extern char g_instName_null[];  // 0x803FEF9C — null instance
extern char g_instName[];       // 0x803FEE68 — valid instance

struct EIStaticSubModel {
    char pad[0xA0];
    void* m_instance;
    const char* GetInstName(int& type);
};

const char* EIStaticSubModel::GetInstName(int& type) {
    void* inst = m_instance;
    type = 4;
    if (inst != 0) return g_instName;
    return g_instName_null;
}
