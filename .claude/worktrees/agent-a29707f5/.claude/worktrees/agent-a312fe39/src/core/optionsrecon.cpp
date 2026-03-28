// optionsrecon.cpp - OptionsRecon small functions
// From: optionsrecon.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/optionsrecon.h"

// ============================================================================
// SDA global: online prefs preserved flag
// r13 - 0x7E64 = r13 - 32356
// Must be placed in SDA for r13-relative addressing to match.
// ============================================================================
extern int s_onlinePrefsPreserved;

// ============================================================================
// OptionsRecon::WriteToMemoryCard(char *, unsigned char)
// 0x80058d24 - 8 bytes
// li r3, 0; blr
// Stubbed - always returns 0 (success/no-op)
// ============================================================================
int OptionsRecon::WriteToMemoryCard(char* filename, unsigned char flags) {
    return 0;
}

// ============================================================================
// OptionsRecon::ReadFromMemoryCard(char *, unsigned char)
// 0x80058e54 - 8 bytes
// li r3, 0; blr
// Stubbed - always returns 0 (success/no-op)
// ============================================================================
int OptionsRecon::ReadFromMemoryCard(char* filename, unsigned char flags) {
    return 0;
}

// ============================================================================
// OptionsRecon::PreservePrefsForOnline(void)
// 0x80058ee8 - 20 bytes
// Saves preference value and sets global flag
// Original: lwz r0,16(r3); li r9,1; stw r0,80(r3); stw r9,-0x7E64(r13); blr
// ============================================================================
// NON_MATCHING - SDA global s_onlinePrefsPreserved needs r13-relative addressing.
// Also register allocation: original uses r0 for member load and r9 for constant,
// GCC uses r9 for member load and may not use r0.
void OptionsRecon::PreservePrefsForOnline(void) {
    m_savedPref = m_pref;
    s_onlinePrefsPreserved = 1;
}

// ============================================================================
// OptionsRecon::RestorePrefsForOnline(void)
// 0x80058f80 - 12 bytes
// lwz r0, 80(r3); stw r0, 16(r3); blr
// ============================================================================
void OptionsRecon::RestorePrefsForOnline(void) {
    m_pref = m_savedPref;
}
