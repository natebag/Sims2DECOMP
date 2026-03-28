// aptaux.h - APT auxiliary classes from aptauxpceorgl.obj
// Contains: EMat4::operator=(EMat4&) (from aptauxpceorgl linkage),
//           AptParagraph destructor

#ifndef APTAUX_H
#define APTAUX_H

#include "types.h"
#include "core/e_mat4.h"

// Forward declarations
class EAHeap;

// ============================================================================
// AptLine - single line in an APT paragraph
// A linked list node with a virtual destructor
// Layout:
//   0x00: next (AptLine*)
//   0x0C: vtable_ptr (void*) - for virtual dispatch
// ============================================================================
struct AptLine {
    AptLine* next;     // 0x00
    u8 pad04[0x08];    // 0x04
    void* vtable_ptr;  // 0x0C - points to vtable with destructor
};

// ============================================================================
// AptParagraph - text paragraph in APT UI system
// Manages a linked list of AptLine objects and associated text data
// Layout:
//   0x00: m_pLines (AptLine*) - head of linked list
//   0x04-0x08: unknown
//   0x0C: m_pTextData (void*) - allocated text/glyph data
//   0x10-0x30: various paragraph properties
//   0x34: m_vtable (void*) - manually managed vtable pointer
// vtable at 0x8045abd0
// Note: This class does NOT use C++ virtual dispatch in the normal sense.
// The vtable pointer at 0x34 is set manually in the destructor.
// ============================================================================
class AptParagraph {
public:
    AptLine* m_pLines;    // 0x00 - linked list of lines
    u8 pad04[0x08];       // 0x04
    void* m_pTextData;    // 0x0C - heap-allocated data
    u8 pad10[0x24];       // 0x10
    void* m_vtable;       // 0x34 - manually managed vtable pointer

    ~AptParagraph(void);
};

// ============================================================================
// AptAuxIDToChar - mapping from ID to APT character
// Used by vector<AptAuxIDToChar> in aptauxpceorgl.obj
// ============================================================================
struct AptAuxIDToChar {
    u8 data[4]; // placeholder - exact layout TBD
};

#endif // APTAUX_H
