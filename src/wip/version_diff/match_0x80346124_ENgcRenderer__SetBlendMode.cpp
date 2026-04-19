// VERSION_DIFF: register allocation — DOL uses r0 for src (lwz r0,4(r4)), all SN ProDG
// versions v3.5/v3.7/v3.81/v3.93 produce r9 for src instead. The swap is consistent
// across all compiler versions and all source structure variations tried:
// - plain src = arg->m_packed
// - register keyword, volatile pointer, pointer cast, implicit CSE (no named var)
// - both -fno-schedule-insns flags
// 11 of 14 instructions functionally correct; only register numbers differ (r0<->r9 swap).
//
// Best C++ (correct logic, wrong regs): sbm_test5.cpp pattern below.
// DOL: lwz r0,4(r4) | addi r9,r0,1 | stw r9,0x510(r3) | rlwinm r7,r0,24,24,31 | ...
// Ours: lwz r9,4(r4) | addi r0,r9,1 | rlwinm×5(r9-based) | stw r0,0x510(r3) | ...
//
// 0x80346124 (56B) ENgcRenderer::SetBlendMode(EDLEntry*)

struct EDLBlend {
    int field_0;
    unsigned int m_packed;
};

struct ENgcRenderer_B {
    char pad[0x510];
    unsigned int m_blendMode;
    char pad2[0x50];
    unsigned char m_alpha;
    unsigned char m_srcColor;
    unsigned char m_dstColor;
    unsigned char m_srcAlpha;
    unsigned char m_blendType;
    void SetBlendMode(EDLBlend* arg);
};

void ENgcRenderer_B::SetBlendMode(EDLBlend* arg) {
    unsigned int src = arg->m_packed;
    m_blendMode = src + 1;
    m_blendType = (src << 16) >> 24;
    m_srcColor  = (src >> 2) & 0x3;
    m_dstColor  = (src >> 4) & 0x3;
    m_srcAlpha  = (src >> 6) & 0x3;
    src &= 0x3;
    m_alpha = src;
}
