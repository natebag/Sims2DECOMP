#ifndef TRACKDATAREADER_H
#define TRACKDATAREADER_H

#include "types.h"

// TrackDataReader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (0 named), 20 methods

class TrackDataReader {
public:
    // Constructors / Destructors
    TrackDataReader(void)  // 0x8033FEB0
    ~TrackDataReader(void);  // 0x8033FEE8

    // Methods
    void operator=(TrackDataReader &);  // 0x8033FF40 (68B)
    void operator=(ERSoundTrackData *);  // 0x8033FF84 (60B)
    void operator--(void);  // 0x8033FFC0 (164B)
    void operator+=(int);  // 0x80340064 (384B)
    void ReadCommand(void);  // 0x803401E4 (604B)
    void Trace(void);  // 0x80340528 (168B)
    bool IsValid(void);  // 0x80340440 (60B)
    void JumpToEnd(void);  // 0x8034047C (172B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (ReadCommand)
    u32 m_field_004;  // 0x004 [R/W] (ReadCommand)
};

#endif // TRACKDATAREADER_H
