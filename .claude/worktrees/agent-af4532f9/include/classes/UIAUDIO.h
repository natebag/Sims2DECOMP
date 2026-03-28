#ifndef UIAUDIO_H
#define UIAUDIO_H

#include "types.h"

// UIAUDIO - struct layout extracted from assembly analysis
// Estimated minimum size: 0x78 (120 bytes)
// 7 known fields (2 named), 31 methods

class UIAUDIO {
public:
    // Constructors / Destructors
    UIAUDIO(void)  // 0x8047ABE0
    ~UIAUDIO(void);  // 0x8047ADD0

    // Methods
    void Instance(void);  // 0x8047BF28 (108B)
    void Update(void);  // 0x8047B834 (100B)
    void PlaySound(unsigned int);  // 0x8047B640 (500B)
    void StopSound(int);  // 0x8047BBEC (288B)
    void AddEntry(char *, unsigned int, char *);  // 0x8047AF9C (224B)
    void RemoveEntry(UIAUDIO::UIAUDIORecord *);  // 0x8047B07C (280B)
    void InstallEntry(char *, unsigned int, char *);  // 0x8047B194 (324B)
    void UnInstallEntry(char *);  // 0x8047B2D8 (280B)
    void UnInstallAllEntries(char *);  // 0x8047B3F0 (160B)
    void ContainsEntry(char *);  // 0x8047B490 (136B)
    /* ? */ GetSound(char *);  // 0x8047B518 (296B)
    void UpdateAudioLoad(int);  // 0x8047B898 (852B)
    void CountAndPrintEntries(void);  // 0x8047BD0C (192B)
    void Shutdown(void);  // 0x8047BF94 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddEntry, ContainsEntry, GetSound, ...)
    u32 m_sound_004;  // 0x004 [R/W] (AddEntry, GetSound, RemoveEntry, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddEntry, InstallEntry, RemoveEntry, ...)
    u32 m_field_00C;  // 0x00C [R/W] (PlaySound, UIAUDIO)
    u32 m_field_010;  // 0x010 [W] (UIAUDIO)
    u32 m_field_014;  // 0x014 [W] (UIAUDIO)
    u8 _pad_018[0x5C];  // 0x018
    u32 m_field_074;  // 0x074 [W] (UIAUDIO, ~UIAUDIO)
};

#endif // UIAUDIO_H
