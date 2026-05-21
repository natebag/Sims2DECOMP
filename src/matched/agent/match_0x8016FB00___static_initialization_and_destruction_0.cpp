// 0x8016FB00 __static_initialization_and_destruction_0 (84B)
// 0.0f -> dst1[3], 1.0f -> dst2[3]; stores interleaved [2][2][0][0][1][1]

extern float g_src0_8016FB00[];  // 0.0f
extern float g_src1_8016FB00[];  // 1.0f
extern float g_dst1_8016FB00[3];
extern float g_dst2_8016FB00[3];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float a = g_src0_8016FB00[0];
    float b = g_src1_8016FB00[0];
    g_dst1_8016FB00[0] = a;
    g_dst2_8016FB00[0] = b;
    g_dst1_8016FB00[1] = a;
    g_dst2_8016FB00[1] = b;
    g_dst1_8016FB00[2] = a;
    g_dst2_8016FB00[2] = b;
}
