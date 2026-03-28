#ifndef ENGCAUDIOSAMPLEMANAGER_H
#define ENGCAUDIOSAMPLEMANAGER_H

#include "types.h"

// ENgcAudioSampleManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD28 (3368 bytes)
// 18 known fields (1 named), 30 methods

class ENgcAudioSampleManager {
public:
    // Constructors / Destructors
    ENgcAudioSampleManager(void)  // 0x808A47A0
    ~ENgcAudioSampleManager(void);  // 0x808A47F4

    // Methods
    void Init(char *);  // 0x808A4840 (72B)
    void heapInit(void);  // 0x808A4FC0 (552B)
    void Shutdown(void);  // 0x808A4888 (56B)
    bool CanCache(EResource *);  // 0x808A48C0 (88B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x808A4918 (1260B)
    void heapAlloc(unsigned int);  // 0x808A51E8 (588B)
    void heapWalk(bool);  // 0x808A5B88 (672B)
    void OnDelRef(ERSampledata *);  // 0x808A4E04 (204B)
    void heapFree(unsigned int);  // 0x808A5898 (752B)
    void heapResortSmaller(ARAMBlock *);  // 0x808A5434 (372B)
    void heapResortLarger(ARAMBlock *);  // 0x808A55A8 (536B)
    void heapFindBlock(unsigned int);  // 0x808A57C0 (112B)
    void heapIsFreeBlock(ARAMBlock *);  // 0x808A5830 (104B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (heapAlloc, heapFree, heapInit)
    u32 m_field_004;  // 0x004 [R/W] (AllocateAndLoadResource, heapFree)
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
    u32 m_field_00C;  // 0x00C [W] (heapFree)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R/W] (AllocateAndLoadResource)
    u32 m_field_018;  // 0x018 [R/W] (AllocateAndLoadResource)
    u32 m_field_01C;  // 0x01C [W] (AllocateAndLoadResource)
    u32 m_field_020;  // 0x020 [W] (AllocateAndLoadResource)
    u32 m_field_024;  // 0x024 [W] (AllocateAndLoadResource)
    s16 m_field_028;  // 0x028 [R] (AllocateAndLoadResource)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R] (AllocateAndLoadResource)
    s16 m_field_030;  // 0x030 [R] (AllocateAndLoadResource)
    u8 _pad_032[2];  // 0x032
    u32 m_field_034;  // 0x034 [R] (AllocateAndLoadResource)
    u8 _pad_038[0x12];  // 0x038
    u16 m_field_04A;  // 0x04A [R] (AllocateAndLoadResource)
    u8 _pad_04C[8];  // 0x04C
    u32 m_field_054;  // 0x054 [W] (ENgcAudioSampleManager)
    u8 _pad_058[0xCC4];  // 0x058
    u32 m_field_D1C;  // 0xD1C [W] (ENgcAudioSampleManager)
    u32 m_field_D20;  // 0xD20 [R/W] (heapInit, heapWalk)
    u32 m_field_D24;  // 0xD24 [R/W] (heapAlloc, heapFree, heapInit, ...)
};

#endif // ENGCAUDIOSAMPLEMANAGER_H
