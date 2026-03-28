#ifndef CSAMPLECHANNEL_H
#define CSAMPLECHANNEL_H

#include "types.h"

// cSampleChannel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 3 known fields (2 named), 24 methods

class cSampleChannel {
public:
    // Constructors / Destructors
    cSampleChannel(cSamplePatch *)  // 0x80345B8C
    ~cSampleChannel(void);  // 0x80345BE4

    // Methods
    void Shutdown(void);  // 0x80345CD8 (64B)
    void Pause(void);  // 0x80346280 (244B)
    void Unpause(void);  // 0x80346374 (244B)
    bool IsPlaying(void);  // 0x803461F8 (136B)
    void NoteOn(void);  // 0x80346070 (264B)
    void NoteOff(void);  // 0x80346178 (128B)
    void SetVolume(int);  // 0x80345C4C (140B)
    void SetPan(int);  // 0x80345ECC (244B)
    void SetPatch(cSamplePatch *);  // 0x80345D18 (436B)
    void Snd(int);  // 0x80345FC0 (176B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Pause, SetPan, SetPatch, ...)
    u32 m_bIsPlaying;  // 0x004 [R/W] (IsPlaying, NoteOff, NoteOn, ...)
    u8 _pad_008[0x10];  // 0x008
    u32 m_field_018;  // 0x018 [R] (Pause, Unpause)
};

#endif // CSAMPLECHANNEL_H
