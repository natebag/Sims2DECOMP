#ifndef ENGCARAM_H
#define ENGCARAM_H

#include "types.h"

// ENgcAram - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (1 named), 16 methods

class ENgcAram {
public:
    // Methods
    void SequentialLoadToARAM(void *, unsigned int, unsigned int);  // 0x809105D4 (376B)
    void Allocate(unsigned int);  // 0x809104B8 (224B)
    void Open(void);  // 0x80910364 (284B)
    void AsyncLoadToARAM(void *, unsigned int, unsigned int, void (*);  // 0x80910778 (556B)
    void Close(void);  // 0x80910480 (56B)
    void AvailableMemory(void);  // 0x80910598 (60B)
    void SequentialLoadFromARAM(void *, unsigned int, unsigned int);  // 0x80910AB0 (376B)
    void AsyncLoadFromARAM(void *, unsigned int, unsigned int, void (*);  // 0x80910C54 (556B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Open)
    u32 m_field_004;  // 0x004 [W] (Open)
};

#endif // ENGCARAM_H
