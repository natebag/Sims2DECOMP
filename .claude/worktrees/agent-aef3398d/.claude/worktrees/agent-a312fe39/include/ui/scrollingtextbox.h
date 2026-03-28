#ifndef SCROLLINGTEXTBOX_H
#define SCROLLINGTEXTBOX_H

#include "types.h"

// Forward declarations
struct EVec2;
struct EVec4;
class ERC;

// ============================================================================
// ScrollingTextBox - Scrolling text display widget
// From: scrollingtextbox.obj
// Layout:
//   +0x00: unknown base
//   +0x04: m_posX (float) - left edge
//   +0x08: m_posY (float) - top edge
//   +0x0C: m_width (float)
//   +0x10: m_height (float)
//   +0x14: m_scrollVelX (float)
//   +0x18: m_scrollVelY (float)
//   +0x24: m_textColor (EVec4*) - pointer to RGBA color
//   +0x34: m_subOffsetX (float)
//   +0x38: m_subOffsetY (float)
// ============================================================================
class ScrollingTextBox {
public:
    ScrollingTextBox(void);
    ~ScrollingTextBox(void);

    // Set position with individual floats (x, y, w, h)
    void SetPosition(float x, float y, float w, float h);
    // Set position from two EVec2 (min, max)
    void SetPosition(EVec2& min, EVec2& max);

    // Set scroll velocity with individual floats
    void SetScrollVelocity(float vx, float vy);
    // Set scroll velocity from EVec2
    void SetScrollVelocity(EVec2& vel);

    // Set text string with line spacing
    void SetString(unsigned short* str, float spacing);

    // Set text color with individual RGBA floats
    void SetTextColor(float r, float g, float b, float a);
    // Set text color from EVec4
    void SetTextColor(EVec4& color);

    // Set sub-pixel offset from EVec2
    void SetSubOffset(EVec2& offset);
    // Set sub-pixel offset with individual floats
    void SetSubOffset(float x, float y);

    // Draw the scrolling text
    void Draw(ERC* rc);

private:
    u32 m_base;            // 0x00
    float m_posX;          // 0x04
    float m_posY;          // 0x08
    float m_width;         // 0x0C
    float m_height;        // 0x10
    float m_scrollVelX;    // 0x14
    float m_scrollVelY;    // 0x18
    u8 m_pad1C[0x08];     // 0x1C
    EVec4* m_textColor;    // 0x24
    u8 m_pad28[0x0C];     // 0x28
    float m_subOffsetX;    // 0x34
    float m_subOffsetY;    // 0x38
};

#endif // SCROLLINGTEXTBOX_H
