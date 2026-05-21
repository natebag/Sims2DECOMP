// 0x80226914 __static_initialization_and_destruction_0 (52B)
// two separate extern float[] (unknown size) force independent lis+lfs for each
// constants at 0x803FE400 = 90.0f, 0x803FE404 = pi/180

extern float g_src1_80226914[];  // unknown size -> absolute addressing (no SDA)
extern float g_src2_80226914[];
extern float g_sda_result_80226914;

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float a = g_src1_80226914[0];
    float b = g_src2_80226914[0];
    float val = a * b;
    g_sda_result_80226914 = val;
}
