#ifndef THUMBNAILLOADER_H
#define THUMBNAILLOADER_H

#include "types.h"

// ThumbnailLoader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x400 (1024 bytes)
// 8 known fields (0 named), 7 methods

class ThumbnailLoader {
public:
    // Constructors / Destructors
    ThumbnailLoader(ObjSelector *)  // 0x802CFE78

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x803311F0 (1076B)
    void CreateEmptyThumbnail(void);  // 0x80331624 (916B)
    void DuplicateThumbnail(ETexture **, ETexture *);  // 0x803319B8 (1272B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (CreateEmptyThumbnail, DoStream, DuplicateThumbnail)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R] (DuplicateThumbnail)
    u32 m_field_008;  // 0x008 [R] (DuplicateThumbnail)
    u32 m_field_00C;  // 0x00C [R] (DuplicateThumbnail)
    u32 m_field_010;  // 0x010 [R] (DuplicateThumbnail)
    u32 m_field_014;  // 0x014 [R] (DuplicateThumbnail)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [R] (CreateEmptyThumbnail, DoStream, DuplicateThumbnail)
    u8 _pad_028[0x3D4];  // 0x028
    u32 m_field_3FC;  // 0x3FC [W] (CreateEmptyThumbnail)
};

#endif // THUMBNAILLOADER_H
