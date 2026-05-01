// MATCH: 0x80039498 EyeToyClient::Debug::GetTierNthRepShader(int,int) | Size: 32 bytes
// FLAGS: -O2 -g0

struct ShaderEntry {
    int field0;
    int shader;
};

struct TierEntry {
    ShaderEntry* shaders;
    int pad[2];
};

extern TierEntry g_tierTable[];

struct EyeToyClient {
    struct Debug {
        static int GetTierNthRepShader(int tier, int n);
    };
};

int EyeToyClient::Debug::GetTierNthRepShader(int tier, int n) {
    return g_tierTable[tier].shaders[n].shader;
}
