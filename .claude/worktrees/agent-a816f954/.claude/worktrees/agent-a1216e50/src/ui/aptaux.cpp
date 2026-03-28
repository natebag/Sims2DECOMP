// aptaux.cpp - APT auxiliary classes from aptauxpceorgl.obj
// Medium-ish functions (slightly above 128 bytes) decompiled from this object
//
// Functions decompiled:
//   EMat4::operator=(EMat4&)         @ 0x8039D348 (136 bytes)
//   AptParagraph::~AptParagraph      @ 0x8039D3D0 (152 bytes)

#include "ui/aptaux.h"
#include "core/eaheap.h"

// ============================================================================
// External references
// ============================================================================
extern "C" {
    EAHeap* MainHeap(void);          // 0x802cff00
}

// AptParagraph vtable (at 0x8045ABD0, offset +8 = 0x8045ABD8)
extern void* AptParagraph_vtable; // 0x8045abd8 (vtable + 8)

// ============================================================================
// EMat4::operator=(EMat4&)
// Address: 0x8039D348, Size: 0x88 (136 bytes)
// Copies all 64 bytes from source to this matrix using integer registers.
// The SN Systems compiler generates paired lwz/stw using GPRs (r9/r10/r11/r12),
// alternating register pairs for pipeline efficiency.
//
// No prologue/epilogue - leaf function, no stack frame.
// r8 = this (saved from r3), r4 = source, returns this in r3
// ============================================================================
// NON_MATCHING - GCC uses single-register lwz/stw pattern instead of the
// original's paired register interleaving (r11/r12 then r9/r10 alternating).
// The logic is identical but instruction scheduling differs.
EMat4& EMat4::operator=(EMat4& other) {
    unsigned int* dst = (unsigned int*)&m[0][0];
    unsigned int* src = (unsigned int*)&other.m[0][0];
    dst[0]  = src[0];  dst[1]  = src[1];
    dst[2]  = src[2];  dst[3]  = src[3];
    dst[4]  = src[4];  dst[5]  = src[5];
    dst[6]  = src[6];  dst[7]  = src[7];
    dst[8]  = src[8];  dst[9]  = src[9];
    dst[10] = src[10]; dst[11] = src[11];
    dst[12] = src[12]; dst[13] = src[13];
    dst[14] = src[14]; dst[15] = src[15];
    return *this;
}

// ============================================================================
// AptParagraph::~AptParagraph
// Address: 0x8039D3D0, Size: 0x98 (152 bytes)
// Destructor: sets vtable at offset 0x34, walks linked list of AptLine objects
// destroying each via virtual dispatch (through line's vtable at offset 0x0C),
// then frees the text data buffer via MainHeap()->Free().
//
// The original also checks __in_chrg (r4) bit 0 to decide whether to
// call __builtin_delete(this). This is SN Systems ABI-specific.
// ============================================================================
// NON_MATCHING - GCC doesn't pass __in_chrg parameter in destructors.
// Also GCC uses bctrl instead of blrl for indirect calls.
// The stmw/lmw prologue/epilogue is also SN Systems specific.
AptParagraph::~AptParagraph(void) {
    // Set vtable pointer (0x8045ABD8 = vtable + 8 adjusted)
    m_vtable = &AptParagraph_vtable;

    // Walk linked list of AptLine objects and destroy each
    AptLine* node = m_pLines;
    if (node != 0) {
        do {
            AptLine* next = node->next;
            if (node != 0) {
                void* vptr = node->vtable_ptr;
                s16 thisAdj = *(s16*)((u8*)vptr + 8);
                void* adjThis = (u8*)node + thisAdj;
                typedef void (*DtorFunc)(void*, int);
                DtorFunc dtor = *(DtorFunc*)((u8*)vptr + 0x0C);
                dtor(adjThis, 3);
            }
            node = next;
        } while (node != 0);
    }

    // Free text data buffer
    void* textData = m_pTextData;
    EAHeap* heap = MainHeap();
    heap->Free(textData);
}
