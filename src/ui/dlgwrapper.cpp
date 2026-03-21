// dlgwrapper.cpp - DlgWrapper (dialog system wrapper)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(dlgwrapper.obj)
//
// Small functions (<=64 bytes) decompiled from the dlgwrapper object file.
// DlgWrapper manages dialog display, positioning, input handling.

#include "types.h"

struct EVec2 { float x, y; };

//=============================================================================
// DlgWrapper
//=============================================================================
class DlgWrapper {
public:
    u8 pad00[0x08];
    void* m_font;           // 0x08 (GetFont)
    void* m_dialogPane;     // 0x0C (placeholder, actual offset from asm)
    u8 pad10[0x10];
    u32 m_flags;            // various bool fields packed
    EVec2 m_dialogPos;      // dialog position
    EVec2 m_dialogSize;     // dialog size
    u8 padRest[0x80];       // remaining fields

    // GetFont
    // Address: 0x8007E5E0, Size: 8
    void* GetFont() {
        return m_font;
    }

    // GetDialogPane
    // Address: 0x8007E5E8, Size: 8
    void* GetDialogPane() {
        return m_dialogPane;
    }

    // IsDialogUp
    // Address: 0x8007E5F0, Size: 24
    // NON_MATCHING - bit field check
    bool IsDialogUp();

    // DialogAccepted
    // Address: 0x8007E608, Size: 24
    // NON_MATCHING - bit field check
    bool DialogAccepted();

    // DialogDeclined
    // Address: 0x8007E620, Size: 24
    // NON_MATCHING - bit field check
    bool DialogDeclined();

    // DialogAlt1
    // Address: 0x8007E638, Size: 24
    // NON_MATCHING - bit field check
    bool DialogAlt1();

    // SetDialogPos
    // Address: 0x8007E650, Size: 20
    void SetDialogPos(EVec2& pos) {
        m_dialogPos.x = pos.x;
        m_dialogPos.y = pos.y;
    }

    // SetDialogPosX
    // Address: 0x8007E664, Size: 8
    void SetDialogPosX(float x) {
        m_dialogPos.x = x;
    }

    // SetDialogPosY
    // Address: 0x8007E66C, Size: 8
    void SetDialogPosY(float y) {
        m_dialogPos.y = y;
    }

    // GetDialogPos
    // Address: 0x8007E674, Size: 8
    EVec2* GetDialogPos() {
        return &m_dialogPos;
    }

    // GetDialogPosX
    // Address: 0x8007E67C, Size: 8
    float GetDialogPosX() const {
        return m_dialogPos.x;
    }

    // GetDialogPosY
    // Address: 0x8007E684, Size: 8
    float GetDialogPosY() const {
        return m_dialogPos.y;
    }

    // GetDialogSize
    // Address: 0x8007E758, Size: 8
    EVec2* GetDialogSize() {
        return &m_dialogSize;
    }

    // SetDialogSizeX
    // Address: 0x8007E6D8, Size: 64
    // NON_MATCHING - float comparison and clamping
    void SetDialogSizeX(float x);

    // SetDialogSizeY
    // Address: 0x8007E718, Size: 64
    // NON_MATCHING - float comparison and clamping
    void SetDialogSizeY(float y);
};
