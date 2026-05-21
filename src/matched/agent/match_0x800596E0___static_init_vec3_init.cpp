// 0x800596E0 __static_initialization_and_destruction_0 (64B)
// loads 2 floats (1.0f, 3.0f) from rodata, stores to 3 non-SDA floats: [0]=src1, [1]=src1, [2]=src2

extern float g_src1_800596E0[];   // 1.0f — unknown size -> lis+lfs
extern float g_src2_800596E0[];   // 3.0f — unknown size -> lis+lfs
extern float g_dst_800596E0[3];   // 12B destination -> absolute

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float a = g_src1_800596E0[0];
    float b = g_src2_800596E0[0];
    g_dst_800596E0[0] = a;
    g_dst_800596E0[1] = a;
    g_dst_800596E0[2] = b;
}
