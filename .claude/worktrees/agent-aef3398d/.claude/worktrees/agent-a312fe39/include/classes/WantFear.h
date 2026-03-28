#ifndef WANTFEAR_H
#define WANTFEAR_H

#include "types.h"

// WantFear - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA2 (162 bytes)
// 14 known fields (0 named), 0 methods

class WantFear {
public:
    // ---- Field Layout (from assembly analysis) ----
    s16 m_field_000;  // 0x000 [R/W] (Bookmark::ApplyReward, Bookmark::DoStream, Bookmark::GetNextBookmarkAlongBranch, ...)
    u8 m_field_002;  // 0x002 [R] (Bookmark::GetType)
    u8 _pad_003[1];  // 0x003
    s16 m_field_004;  // 0x004 [R/W] (Bookmark::ApplyReward, Bookmark::DoStream, Bookmark::GetBaseShader, ...)
    s16 m_field_006;  // 0x006 [R] (Bookmark::IsValid)
    s16 m_field_008;  // 0x008 [R/W] (Bookmark::DoStream, Bookmark::GetNextBookmarkAlongBranch, Bookmark::IsCompleted, ...)
    u8 m_field_00A;  // 0x00A [R] (Bookmark::GetBaseShader, Bookmark::GetText)
    u8 m_field_00B;  // 0x00B [R] (Bookmark::GetNextBookmarkAlongBranch, Bookmark::ResetCountdown)
    u32 m_field_00C;  // 0x00C [R] (Bookmark::GetBaseShader, Bookmark::GetText)
    u8 _pad_010[8];  // 0x010
    u32 m_field_018;  // 0x018 [R] (Bookmark::ApplyReward)
    u8 m_field_01C;  // 0x01C [R] (Bookmark::SatisfiedBy)
    u8 m_field_01D;  // 0x01D [R] (Bookmark::GetNextBookmarkAlongBranch)
    u8 _pad_01E[6];  // 0x01E
    s16 m_field_024;  // 0x024 [R] (Bookmark::DoStream)
    u8 _pad_026[2];  // 0x026
    u32 m_field_028;  // 0x028 [R] (Bookmark::DoStream)
    u8 _pad_02C[0x74];  // 0x02C
    s16 m_field_0A0;  // 0x0A0 [R] (Bookmark::IsCompleted, Bookmark::IsValid)
};

#endif // WANTFEAR_H
