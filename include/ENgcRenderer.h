// ENgcRenderer class layout - reverse engineered from matched functions
// Based on analysis of 15 matched functions and asm_decomp patterns
#pragma once

class EDLEntry;
class ENgcRenderStateCache;
class ENgcTexture;
class ERTexture;
class EMat4;
class EVec3;
class EVec4;

// ENgcRenderer - GameCube renderer class
// Very large structure (> 18KB total)
struct ENgcRenderer {
    // Base fields (0x0000 - 0x0400 range)
    /* 0x0000 */ char _pad0[0x34c];
    /* 0x034C */ int m_externalFrameBuffer;
    /* 0x0350 */ char _pad1[0x54];
    
    // Material/alpha fields (0x03A4 - 0x0548 range)
    /* 0x03A4 */ float m_alpha;
    /* 0x03A8 */ char _pad2[0x164];
    /* 0x050C */ char _pad2b[4];
    /* 0x0510 */ int m_dirty;
    /* 0x0514 */ char _pad3[4];
    /* 0x0518 */ char m_matdata[0x30];
    /* 0x0548 */ char _pad4[0x1c8];
    
    // Model matrix fields (0x0710 - 0x4574 range)
    /* 0x0710 */ char _pad5[0x60];
    /* 0x0770 */ char m_modelMatrices[0x400];  // 0x400 bytes at 0x770
    /* 0x0B70 */ char _pad_mm[0x3a00];         // gap to 0x4570
    /* 0x4570 */ int m_modelMatrixCount;
    
    // State cache (0x4D8C range)
    /* 0x4574 */ char _pad6[0x818];
    /* 0x4D8C */ ENgcRenderStateCache* m_pStateCache;
    
    // Frame buffer management (0x8320 range)
    /* 0x4D90 */ char _pad7[0x3590];
    /* 0x8320 */ int m_frameBufferIndex;
    /* 0x8324 */ char _pad8[0x11c];
    /* 0x8440 */ int m_renderTarget;
    
    // Large gap to texture array
    /* 0x8444 */ char _pad9[0x21f4];
    
    // Texture array at end (0x4638 range)
    /* 0x4638 */ ERTexture* m_currentTexture[8];
    
    // vtable at end (SN Systems ABI)
    /* 0x4658 */ void* m_vtable;
};

// Size: approximately 0x4660 bytes (~18KB)
// Note: Fields marked with // MATCHED have been verified through matching functions
// Other offsets are approximate and subject to refinement
