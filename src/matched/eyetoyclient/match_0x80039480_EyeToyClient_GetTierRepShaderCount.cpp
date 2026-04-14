// 0x80039480 EyeToyClient::Debug::GetTierRepShaderCount (24b)
extern int g_repShaderTable[3][3];  /* oversized to force lis+lwzx */

struct EyeToyClientDebug {
    static int GetTierRepShaderCount(int tier);
};

int EyeToyClientDebug::GetTierRepShaderCount(int tier) {
    return g_repShaderTable[tier][1];
}
