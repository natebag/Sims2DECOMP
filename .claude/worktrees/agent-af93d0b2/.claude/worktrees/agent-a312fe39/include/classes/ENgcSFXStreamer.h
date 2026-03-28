#ifndef ENGCSFXSTREAMER_H
#define ENGCSFXSTREAMER_H

#include "types.h"

// ENgcSFXStreamer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1B6 (438 bytes)
// 4 known fields (2 named), 30 methods

class ENgcSFXStreamer {
public:
    // Constructors / Destructors
    ENgcSFXStreamer(void)  // 0x808DA5DC
    ~ENgcSFXStreamer(void);  // 0x808DA714

    // Methods
    bool IsPlaying(unsigned int);  // 0x808DA92C (232B)
    void Pause(unsigned int);  // 0x808DB57C (376B)
    void Play(unsigned int, ERSampledata *);  // 0x808DAE4C (1840B)
    void Update(void);  // 0x808DA764 (456B)
    void Allocate(ERSampledata *, unsigned char);  // 0x808DAA14 (1080B)
    void Free(unsigned int);  // 0x808DB6F4 (408B)
    void SetPitchBend(unsigned int, float);  // 0x808DB88C (224B)
    void SetVolume(unsigned int, float);  // 0x808DBE60 (428B)
    void SetPan(unsigned int, float);  // 0x808DC00C (428B)
    void SetLeftVolume(unsigned int, int);  // 0x808DB9B4 (376B)
    void SetRightVolume(unsigned int, int);  // 0x808DBCE4 (380B)
    void SetLeftVolume(unsigned int, float);  // 0x808DB96C (72B)
    void SetRightVolume(unsigned int, float);  // 0x808DBB2C (440B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_rightVolume;  // 0x000 [R] (Free, Pause, Play, ...)
    u8 _pad_004[0x20];  // 0x004
    u32 m_field_024;  // 0x024 [R] (Free)
    u8 _pad_028[0x10];  // 0x028
    u32 m_rightVolume_038;  // 0x038 [R] (SetRightVolume)
    u8 _pad_03C[0x176];  // 0x03C
    u32 m_field_1B2;  // 0x1B2 [R] (Update)
};

#endif // ENGCSFXSTREAMER_H
