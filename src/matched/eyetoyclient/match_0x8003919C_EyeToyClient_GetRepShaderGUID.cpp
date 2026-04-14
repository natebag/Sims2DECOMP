// 0x8003919C EyeToyClient::GetRepShaderGUID (28b)
struct RepShaderEntry { int* guid; char pad[8]; };
extern RepShaderEntry g_repShaderTable[3];

struct EyeToyClient {
    static int GetRepShaderGUID(int idx);
};

int EyeToyClient::GetRepShaderGUID(int idx) {
    return *g_repShaderTable[idx].guid;
}
