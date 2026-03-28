#ifndef THUMBNAILCOMPRESSER_H
#define THUMBNAILCOMPRESSER_H

#include "types.h"

// ThumbnailCompresser - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (0 named), 4 methods

class ThumbnailCompresser {
public:
    // Methods
    void Decode(unsigned char *, int, unsigned char *, int);  // 0x8029D148 (656B)
    void Encode(unsigned char *, int, unsigned char *, int);  // 0x8029CE6C (732B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (Decode, Encode)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (Decode, Encode)
    u32 m_field_008;  // 0x008 [R/W] (Decode, Encode)
};

#endif // THUMBNAILCOMPRESSER_H
