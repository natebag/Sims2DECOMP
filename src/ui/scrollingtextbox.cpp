// scrollingtextbox.cpp - Scrolling text box UI widget small functions
// From: scrollingtextbox.obj
// Small functions (<=64 bytes) decompiled from this object

#include "ui/scrollingtextbox.h"
#include "core/e_vec3.h"
#include "core/e_mat4.h"  // for EVec4

// ============================================================================
// ScrollingTextBox::SetPosition(float, float, float, float)
// 0x8006CA24 - 20 bytes
// Sets position from 4 individual floats: x(f1), y(f2), w(f3), h(f4)
// ============================================================================
// stfs f4,0x10(r3); stfs f1,0x04(r3); stfs f3,0x08(r3); stfs f2,0x0c(r3); blr
// NON_MATCHING - SN Systems reorders stores (f4,f1,f3,f2); GCC writes in parameter order
void ScrollingTextBox::SetPosition(float x, float y, float w, float h) {
    m_posX = x;
    m_posY = y;
    m_width = w;
    m_height = h;
}

// ============================================================================
// ScrollingTextBox::SetPosition(EVec2 &, EVec2 &)
// 0x8006CA38 - 36 bytes
// Sets position from two EVec2 (min and max corners)
// ============================================================================
// lwz r9,4(r4); lwz r0,0(r4); stw r9,8(r3); stw r0,4(r3)
// lwz r9,4(r5); lwz r0,0(r5); stw r9,0x10(r3); stw r0,0x0c(r3); blr
// NON_MATCHING - SN Systems loads y before x; GCC loads in field order
void ScrollingTextBox::SetPosition(EVec2& min, EVec2& max) {
    m_posX = min.x;
    m_posY = min.y;
    m_width = max.x;
    m_height = max.y;
}

// ============================================================================
// ScrollingTextBox::SetScrollVelocity(float, float)
// 0x8006CA5C - 12 bytes
// Sets scroll velocity from individual floats
// ============================================================================
// stfs f2,0x18(r3); stfs f1,0x14(r3); blr
// NON_MATCHING - SN Systems stores vy before vx; GCC stores in parameter order
void ScrollingTextBox::SetScrollVelocity(float vx, float vy) {
    m_scrollVelX = vx;
    m_scrollVelY = vy;
}

// ============================================================================
// ScrollingTextBox::SetScrollVelocity(EVec2 &)
// 0x8006CA68 - 20 bytes
// Sets scroll velocity from EVec2
// ============================================================================
// lwz r0,4(r4); lwz r9,0(r4); stw r0,0x18(r3); stw r9,0x14(r3); blr
// NON_MATCHING - SN Systems loads y before x; GCC loads in field order
void ScrollingTextBox::SetScrollVelocity(EVec2& vel) {
    m_scrollVelX = vel.x;
    m_scrollVelY = vel.y;
}

// ============================================================================
// ScrollingTextBox::SetTextColor(float, float, float, float)
// 0x8006CB6C - 44 bytes
// Sets text color RGBA on the pointed-to EVec4
// ============================================================================
// lwz r9,0x24(r3); cmpwi r9,0; beqlr-
// stfs f1,0(r9); lwz r9,0x24(r3); stfs f2,4(r9)
// lwz r11,0x24(r3); stfs f3,8(r11)
// lwz r9,0x24(r3); stfs f4,0x0c(r9); blr
// NON_MATCHING - SN Systems reloads m_textColor ptr between each store; GCC caches it
void ScrollingTextBox::SetTextColor(float r, float g, float b, float a) {
    if (m_textColor == 0) {
        return;
    }
    m_textColor->x = r;
    m_textColor->y = g;
    m_textColor->z = b;
    m_textColor->w = a;
}

// ============================================================================
// ScrollingTextBox::SetTextColor(EVec4 &)
// 0x8006CB98 - 48 bytes
// Copies EVec4 color to the pointed-to text color
// ============================================================================
// lwz r9,0x24(r3); cmpwi r9,0; beqlr-
// lfs f0,0(r4); stfs f0,0(r9); lfs f13,4(r4); stfs f13,4(r9)
// lfs f0,8(r4); stfs f0,8(r9); lfs f13,0x0c(r4); stfs f13,0x0c(r9); blr
// NON_MATCHING - SN Systems interleaves load/store pairs; GCC loads all then stores all
void ScrollingTextBox::SetTextColor(EVec4& color) {
    if (m_textColor == 0) {
        return;
    }
    m_textColor->x = color.x;
    m_textColor->y = color.y;
    m_textColor->z = color.z;
    m_textColor->w = color.w;
}

// ============================================================================
// ScrollingTextBox::SetSubOffset(EVec2 &)
// 0x8006CBC8 - 20 bytes
// Sets sub-pixel offset from EVec2
// ============================================================================
// lwz r0,4(r4); lwz r9,0(r4); stw r0,0x38(r3); stw r9,0x34(r3); blr
// NON_MATCHING - SN Systems loads y before x; GCC loads in field order
void ScrollingTextBox::SetSubOffset(EVec2& offset) {
    m_subOffsetX = offset.x;
    m_subOffsetY = offset.y;
}

// ============================================================================
// ScrollingTextBox::SetSubOffset(float, float)
// 0x8006CBDC - 12 bytes
// Sets sub-pixel offset from individual floats
// ============================================================================
// stfs f2,0x38(r3); stfs f1,0x34(r3); blr
// NON_MATCHING - SN Systems stores y before x; GCC stores in parameter order
void ScrollingTextBox::SetSubOffset(float x, float y) {
    m_subOffsetX = x;
    m_subOffsetY = y;
}
