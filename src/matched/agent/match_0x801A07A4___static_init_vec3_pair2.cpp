// 0x801A07A4 __static_initialization_and_destruction_0 (84B)
extern float g_src0_801A07A4[];
extern float g_src1_801A07A4[];
extern float g_dst1_801A07A4[3];
extern float g_dst2_801A07A4[3];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float a = g_src0_801A07A4[0];
    float b = g_src1_801A07A4[0];
    g_dst1_801A07A4[0] = a;
    g_dst1_801A07A4[1] = a;
    g_dst1_801A07A4[2] = b;
    g_dst2_801A07A4[0] = a;
    g_dst2_801A07A4[1] = a;
    g_dst2_801A07A4[2] = b;
}
