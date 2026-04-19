/* ENgcRenderer::SetBlendMode(BlendModeState const&) at 0x80346124 (56B) */
/* VERSION_DIFF: Systemic register allocation mismatch.
 * SN ProDG allocates rlwinm destinations: r7, r11, r10, r8, r0.
 * GCC reuses r9 (freed from li-r9-temp for m_dirty) for the first rlwinm,
 * then r11, r8, r7, r0. Register numbers differ throughout and store ordering
 * changes as a consequence. Unfixable without pinning every extraction register.
 * Logic is correct; bytes differ only in register encoding.
 */

struct BlendModeParams_SBM {
    int _pad0;
    unsigned int bits;  // offset 4: packed blend fields
};

struct ENgcRenderer_SBM {
    char _pad[0x510];
    int m_dirty;        // 0x510
    char _pad2[0x50];
    unsigned char m_blendSrc;    // 0x564
    unsigned char m_blendDst;    // 0x565
    unsigned char m_blendAlpha;  // 0x566
    unsigned char m_blendOp;     // 0x567
    unsigned char m_blendFactor; // 0x568
    void SetBlendMode(const BlendModeParams_SBM& p);
};

void ENgcRenderer_SBM::SetBlendMode(const BlendModeParams_SBM& p) {
    m_dirty = 1;
    unsigned int bits = p.bits;
    m_blendDst    = (bits >> 2) & 3;
    m_blendSrc    = bits & 3;
    m_blendAlpha  = (bits >> 4) & 3;
    m_blendOp     = (bits >> 6) & 3;
    m_blendFactor = (bits & 0xFF00u) >> 8;
}
