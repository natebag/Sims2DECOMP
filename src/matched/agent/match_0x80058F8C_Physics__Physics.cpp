// 0x80058F8C (72B) Physics::Physics(void)
// Zero-init 12 float fields (offsets 0-44) via non-SDA 0.0f constant.
// GCC allocates r9=self, r10=self+12, r11=self+24 (shared with lis intermediate).
// Explicit pointer arithmetic forces addi r10/r11 base pointer computations.

extern float kPhysicsZero[4];  // non-SDA 0.0f at 0x803D3E08 — [4] forces lis+lfs

struct Physics_PC {
    Physics_PC();
};

Physics_PC::Physics_PC() {
    float* base = (float*)this;
    float zero = kPhysicsZero[0];
    float* p10 = base + 3;   // self+12
    float* p11 = base + 6;   // self+24
    base[2] = zero;   // offset 8
    base[1] = zero;   // offset 4
    base[0] = zero;   // offset 0
    p10[2] = zero;    // offset 20 (GCC reverses pair → emits 4(r10) first)
    p10[1] = zero;    // offset 16
    base[3] = zero;   // offset 12
    p11[2] = zero;    // offset 32 (GCC reverses pair → emits 4(r11) first)
    p11[1] = zero;    // offset 28
    base[6] = zero;   // offset 24 (GCC rotates last→first: [24,36,40,44]→[44,24,36,40])
    base[9] = zero;   // offset 36
    base[10] = zero;  // offset 40
    base[11] = zero;  // offset 44
}
