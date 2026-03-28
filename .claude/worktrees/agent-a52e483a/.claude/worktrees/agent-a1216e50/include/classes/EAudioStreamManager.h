#ifndef EAUDIOSTREAMMANAGER_H
#define EAUDIOSTREAMMANAGER_H

#include "types.h"

// EAudioStreamManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD20 (3360 bytes)
// 7 known fields (1 named), 10 methods

class EAudioStreamManager {
public:
    // Constructors / Destructors
    EAudioStreamManager(void)  // 0x8088368C
    ~EAudioStreamManager(void);  // 0x80883468

    // Methods
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x808832A4 (452B)
    void AddRef(unsigned int, EFile *, int);  // 0x808835D4 (92B)
    void AddRef(char *, EFile *, int);  // 0x80883630 (92B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (AllocateAndLoadResource)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [W] (AllocateAndLoadResource)
    u32 m_field_018;  // 0x018 [W] (AllocateAndLoadResource)
    u32 m_field_01C;  // 0x01C [W] (AllocateAndLoadResource)
    u8 _pad_020[0x34];  // 0x020
    u32 m_field_054;  // 0x054 [W] (EAudioStreamManager)
    u8 _pad_058[0xCC4];  // 0x058
    u32 m_field_D1C;  // 0xD1C [W] (EAudioStreamManager)
};

#endif // EAUDIOSTREAMMANAGER_H
