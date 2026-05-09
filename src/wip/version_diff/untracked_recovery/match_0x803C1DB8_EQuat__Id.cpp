// MATCH: 0x803C1DB8 EQuat::Id(void) | Size: 40 bytes
// FLAGS: -O2 -g0

extern float g_zero __attribute__((section(".data")));
extern float g_one __attribute__((section(".data")));

struct EQuat {
    float x;
    float y;
    float z;
    float w;
    void Id();
};

void EQuat::Id() {
    float* f = &x;
    f[0] = g_zero;
    f[3] = g_one;
    f[2] = g_zero;
    f[1] = g_zero;
}
