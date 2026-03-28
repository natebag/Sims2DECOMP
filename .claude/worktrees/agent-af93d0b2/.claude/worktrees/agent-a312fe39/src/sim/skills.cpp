// skills.cpp - Decompiled small functions from skilllookup.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\skilllookup.obj
//
// 4 small functions (<=64 bytes) decompiled

#include "sim/skills.h"

// ============================================================================
// External references
// ============================================================================

// GlobalSkillTables destructor (at 0x803AD4D4)
// Called with r4=3 to indicate full delete
extern void GlobalSkillTables_dtor(GlobalSkillTables* tables, int mode);

// ============================================================================
// DestroySkillLookup
// Address: 0x80142124, Size: 56 bytes
// NON_MATCHING - SDA-relative access (r13-31660) for sTables global
// Destroys the skill lookup tables if they exist
// ============================================================================
void DestroySkillLookup() {
    if (sTables != 0) {
        sTables->~GlobalSkillTables();
    }
    sTables = 0;
}

// ============================================================================
// GetLegacyPersonSkillTable
// Address: 0x80142944, Size: 12 bytes
// MATCHING
// Returns the legacy person skill table from the global tables
// ============================================================================
void* GetLegacyPersonSkillTable() {
    return sTables->m_legacyPersonSkillTable;
}

// ============================================================================
// GetLegacyGlobalSkillTable
// Address: 0x80142950, Size: 12 bytes
// MATCHING
// Returns the legacy global skill table
// ============================================================================
void* GetLegacyGlobalSkillTable() {
    return sTables->m_legacyGlobalSkillTable;
}

// ============================================================================
// GetMiscSkillTable
// Address: 0x8014295C, Size: 12 bytes
// MATCHING
// Returns the miscellaneous skill table
// ============================================================================
void* GetMiscSkillTable() {
    return sTables->m_miscSkillTable;
}
