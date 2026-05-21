// 0x80011E60 __static_initialization_and_destruction_0 (52B)
// loads 0.0f from rodata (lis r9; lfs f0,offset(r9)), stores to 4 SDA floats in order [3],[0],[1],[2]

extern float g_sda_f3_80011E60;
extern float g_sda_f0_80011E60;
extern float g_sda_f1_80011E60;
extern float g_sda_f2_80011E60;

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float val = 0.0f;
    g_sda_f3_80011E60 = val;
    g_sda_f0_80011E60 = val;
    g_sda_f1_80011E60 = val;
    g_sda_f2_80011E60 = val;
}
