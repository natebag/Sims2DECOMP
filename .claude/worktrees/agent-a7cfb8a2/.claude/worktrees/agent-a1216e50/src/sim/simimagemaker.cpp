// simimagemaker.cpp - Sim portrait/image maker small functions
// From: simimagemaker.obj
// Small functions (<=64 bytes) decompiled from this object

#include "sim/simimagemaker.h"

// ============================================================================
// External references
// ============================================================================

// SimImageMaker::SetToDefaultValues (0x8006ea14)
// SimImageMaker::Shutdown (0x8006e988)
// __static_initialization_and_destruction_0 (0x800703ec)

// ============================================================================
// SimImageMaker::Init(void)
// 0x8006E964 - 36 bytes
// Calls SetToDefaultValues then returns 1 (success)
// ============================================================================
// stwu r1,-8(r1); mflr r0; stw r0,12(r1)
// bl SimImageMaker::SetToDefaultValues
// li r3,1
// lwz r0,12(r1); mtlr r0; addi r1,r1,8; blr
// NON_MATCHING - GCC reorders li r3,1 relative to epilog
BOOL SimImageMaker::Init(void) {
    SetToDefaultValues();
    return TRUE;
}

// ============================================================================
// SimImageMaker::Reset(void)
// 0x8006E9D8 - 60 bytes
// Calls Shutdown, Init, then SetToDefaultValues again
// ============================================================================
// stwu r1,-16(r1); mflr r0; stmw r30,8(r1); stw r0,20(r1)
// mr r30,r3; bl SimImageMaker::Shutdown
// mr r3,r30; bl SimImageMaker::Init
// mr r3,r30; bl SimImageMaker::SetToDefaultValues
// lwz r0,20(r1); mtlr r0; lmw r30,8(r1); addi r1,r1,16; blr
// NON_MATCHING - GCC uses stw/lwz for r31; original uses stmw/lmw for r30
void SimImageMaker::Reset(void) {
    Shutdown();
    Init();
    SetToDefaultValues();
}

// ============================================================================
// SimImageMaker::SetGender(bool)
// 0x8006EBCC - 8 bytes
// Sets gender flag at offset +0x88
// ============================================================================
// stw r4,0x88(r3); blr
void SimImageMaker::SetGender(bool gender) {
    m_gender = gender;
}

// ============================================================================
// SimImageMaker::SetSkinShader(EShader *)
// 0x8006EBD4 - 8 bytes
// Sets skin shader pointer at offset +0x8C
// ============================================================================
// stw r4,0x8c(r3); blr
void SimImageMaker::SetSkinShader(EShader* shader) {
    m_skinShader = shader;
}

// ============================================================================
// SimImageMaker::SetModel(eBodyPartS2C, EIStaticModel *)
// 0x8006EBDC - 24 bytes
// Sets model for a body part (bounds-checked)
// ============================================================================
// cmpwi r4,25; bgtlr-; slwi r0,r4,2; addi r9,r3,0x90
// stwx r5,r9,r0; blr
// NON_MATCHING - GCC computes offset differently (addi+slwi vs slwi+addi)
void SimImageMaker::SetModel(eBodyPartS2C part, EIStaticModel* model) {
    if ((int)part > 25) {
        return;
    }
    m_models[part] = model;
}

// ============================================================================
// SimImageMaker::OverrideImageSize(unsigned int, unsigned int, unsigned int)
// 0x8006ECAC - 16 bytes
// Sets width, height, and depth
// ============================================================================
// stw r6,8(r3); stw r4,0(r3); stw r5,4(r3); blr
// NON_MATCHING - SN Systems stores depth first; GCC stores in parameter order
void SimImageMaker::OverrideImageSize(unsigned int width, unsigned int height, unsigned int depth) {
    m_width = width;
    m_height = height;
    m_depth = depth;
}

// ============================================================================
// global constructors keyed to {anonymous}::kClearPinkArray
// 0x80070554 - 44 bytes
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================
// li r4,0; li r3,1; ori r4,r4,0xFFFF
// bl __static_initialization_and_destruction_0
// NON_MATCHING - compiler-generated static init wrapper
