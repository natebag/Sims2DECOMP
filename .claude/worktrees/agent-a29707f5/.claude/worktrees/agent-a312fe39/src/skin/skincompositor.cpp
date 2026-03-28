// skincompositor.cpp - Decompiled small functions from skincompositor.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\skincompositor.obj
//
// 3 small functions (<=64 bytes) decompiled from skincompositor.obj
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   NON_MATCHING: SkinCompositor::~SkinCompositor (destructor conditional delete codegen)
//   NON_MATCHING: SkinCompositor::CreateSkinQuadrantHiRes (tail call vs inline)
//   NON_MATCHING: SkinCompositor::CreateSkinQuadrantLoRes (tail call vs inline)

#include "skin/skincompositor.h"

// External functions
extern void __builtin_delete(void* ptr);

// ============================================================================
// SkinCompositor::~SkinCompositor
// Address: 0x80075B70 | Size: 64 bytes
// NON_MATCHING - GCC generates different destructor conditional delete sequence
//
// Original does:
//   calls Reset()
//   checks r4 (second param, hidden __in_chrg) bit 0
//   if set, calls __builtin_delete(this)
//
// GCC may generate different register usage for the conditional delete
// ============================================================================
SkinCompositor::~SkinCompositor() {
    Reset();
}

// ============================================================================
// SkinCompositor::CreateSkinQuadrantHiRes
// Address: 0x80075C80 | Size: 36 bytes
// NON_MATCHING - GCC may inline or generate different call sequence
//
// Original: sets r7=0 (lowRes=false), tail-calls CreateSkin
// ============================================================================
void SkinCompositor::CreateSkinQuadrantHiRes(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc) {
    CreateSkin(tex, quadrant, desc, false);
}

// ============================================================================
// SkinCompositor::CreateSkinQuadrantLoRes
// Address: 0x80075CA4 | Size: 36 bytes
// NON_MATCHING - GCC may inline or generate different call sequence
//
// Original: sets r7=1 (lowRes=true), tail-calls CreateSkin
// ============================================================================
void SkinCompositor::CreateSkinQuadrantLoRes(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc) {
    CreateSkin(tex, quadrant, desc, true);
}
