#ifndef SKILLS_H
#define SKILLS_H

#include "types.h"

// Forward declarations
class cXPerson;
class cXObject;
class AnimRef;
struct AnimTable;
struct StackElem;
struct AnimateNewParam;

// ============================================================================
// GlobalSkillTables - Container for skill lookup tables
// Object file: skilllookup.obj
//
// Layout (from disassembly):
//   +0x18: void* m_legacyPersonSkillTable
//   +0x1C: void* m_legacyGlobalSkillTable
//   +0x20: void* m_miscSkillTable
// ============================================================================
struct GlobalSkillTables {
    u8   m_pad00[0x18];               // +0x00
    void* m_legacyPersonSkillTable;   // +0x18
    void* m_legacyGlobalSkillTable;   // +0x1C
    void* m_miscSkillTable;           // +0x20

    ~GlobalSkillTables();
};

// ============================================================================
// Skill lookup functions
// ============================================================================

// Stored in SDA at r13-31660
extern GlobalSkillTables* sTables;

void InitSkillLookup();
void DestroySkillLookup();

void* GetLegacyPersonSkillTable();
void* GetLegacyGlobalSkillTable();
void* GetMiscSkillTable();

#endif // SKILLS_H
