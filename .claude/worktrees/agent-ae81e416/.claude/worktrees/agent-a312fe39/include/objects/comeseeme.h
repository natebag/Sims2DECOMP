#ifndef COMESEEME_H
#define COMESEEME_H

#include "types.h"

// Forward declarations
class cXObject;
class ObjSelector;

// ============================================================================
// FTilePt - Floor tile position (from comeseeme.obj)
// Layout:
//   +0x00: int m_x
//   +0x04: int m_y
// ============================================================================
struct FTilePt {
    int m_x;  // +0x00
    int m_y;  // +0x04

    bool operator==(FTilePt& other) const;
};

// ============================================================================
// Come See Me functions
// Object file: comeseeme.obj
// ============================================================================

// Global selector pointer, stored SDA-relative at r13-21508
extern void* g_pComeSeeMeSelector;

ObjSelector* GetComeSeeMeSelector();
cXObject* GetComeSeeMe(cXObject* obj);
void RemoveComeSeeMeObjects();
void UpdateComeSeeMeObjects();

#endif // COMESEEME_H
