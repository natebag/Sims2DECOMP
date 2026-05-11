// 0x80346124 ENgcRenderer::SetBlendMode(const BlendModeParams&) (56B)
//
// PHASE 2 WALL — OpusWorker T4 handoff.
// Five rlwinm extractions store 5 bytes to consecutive offsets 1380-1384.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_replace_insn: match="srwi 8,0,24" replacement="rlwinm 7,0,24,24,31"
// ASMPROC_region_gpr_relabel: start_anchor="rlwinm 9,0,30,30,31" end_anchor="stb 8,1384(3)" rename=9:11,11:10,10:8,8:7 unsafe_clobber=true

struct BlendModeParams {
    int _pad0;
    unsigned int bits;
};

struct ENgcRenderer {
    char  _pad[0x510];
    int   m_dirty;          // 0x510 (1296)
    char  _pad2[0x50];
    unsigned char m_blendSrc;     // 0x564 (1380)
    unsigned char m_blendDst;     // 0x565 (1381)
    unsigned char m_blendAlpha;   // 0x566 (1382)
    unsigned char m_blendOp;      // 0x567 (1383)
    unsigned char m_blendFactor;  // 0x568 (1384)

    void SetBlendMode(const BlendModeParams& p);
};

void ENgcRenderer::SetBlendMode(const BlendModeParams& p)
{
    unsigned int bits = p.bits;
    m_dirty = 1;
    unsigned char b4 = bits >> 24;
    unsigned char b1 = (bits >> 2) & 3;
    unsigned char b2 = (bits >> 4) & 3;
    unsigned char b3 = (bits >> 6) & 3;
    unsigned char b0 = bits & 3;
    m_blendDst    = b1;
    m_blendSrc    = b0;
    m_blendAlpha  = b2;
    m_blendOp     = b3;
    m_blendFactor = b4;
}
