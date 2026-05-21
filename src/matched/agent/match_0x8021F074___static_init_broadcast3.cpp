// 0x8021F074 __static_initialization_and_destruction_0 (56B)
// loads -1000.0f from rodata, stores to 3 consecutive non-SDA floats

extern float g_src_8021F074[];    // unknown size -> lis+lfs (absolute)
extern float g_dst_8021F074[3];   // 12B -> absolute (non-SDA)

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    float val = g_src_8021F074[0];
    volatile float* p = g_dst_8021F074;
    p[0] = val;
    p[1] = val;
    p[2] = val;
}
