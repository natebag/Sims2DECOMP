#if 0 // SKIP
// e_window_large.cpp - EWindow large functions (257-1024 bytes)
// Object file: engine_ngc_release_dvd.lib(e_window.obj)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class EWindow;
class ERC;
struct EVec2 { float x, y; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct TRectF { float left, top, right, bottom; };
struct EViewport;

extern "C" void EMat4_Identity(void* mat);
extern "C" void EMat4_Multiply(void* out, void* a, void* b);
extern "C" void ERC_ViewMatrix(void* rc, void* mat, int mode, float param);
extern "C" void ERC_ProjectionMatrix(void* rc, void* mat);
extern "C" void ERC_WindowMatrix(void* rc, void* mat);
extern "C" void ERC_Viewport(void* rc, void* vp);
extern "C" void ERC_Scissor(void* rc, void* rect);
extern "C" void ERC_ClipRect(void* rc, void* rect);

// EWindow layout (from disassembly analysis):
// 0x000 = viewport rect (16 bytes)
// 0x010 = scissor rect (16 bytes)
// 0x020 = clip rect (16 bytes)
// 0x030 = view params
// 0x040 = projection matrix (64 bytes)
// 0x080 = view matrix (64 bytes)
// 0x0C0 = window matrix (64 bytes)
// 0x100 = combined matrix (64 bytes)
// 0x140 = fov, aspect, near, far
// 0x150 = flags
// 0x3B0 = screen size
// 0x3B8 = screenshot flags

struct EWindow {
    TRectF m_viewportRect;       // 0x000
    TRectF m_scissorRect;        // 0x010
    TRectF m_clipRect;           // 0x020
    u8 pad030[0x10];             // 0x030
    float m_projMat[16];         // 0x040
    float m_viewMat[16];         // 0x080
    float m_windowMat[16];       // 0x0C0
    float m_combinedMat[16];     // 0x100
    float m_fov;                 // 0x140
    float m_aspect;              // 0x144
    float m_nearPlane;           // 0x148
    float m_farPlane;            // 0x14C
    u32 m_flags;                 // 0x150
    u8 pad154[0x25C];            // 0x154
    float m_screenWidth;         // 0x3B0
    float m_screenHeight;        // 0x3B4
    u32 m_screenshotMode;        // 0x3B8

    void CalcWindowMat();
    void CalcClip();
    void ScaleForScreenshot(bool enable, int x, int y, int w, int h);
    void Select(ERC* rc);
};

// ============================================================================
// EWindow::CalcWindowMat(void)
// Address: 0x8030035C
// Size: 324 bytes
// NON_MATCHING - calculates window transformation matrix
// ============================================================================
void EWindow::CalcWindowMat(void)
{
    // Calculate viewport-to-screen transformation
    float width = m_viewportRect.right - m_viewportRect.left;
    float height = m_viewportRect.bottom - m_viewportRect.top;

    // Identity base
    EMat4_Identity(m_windowMat);

    // Scale to viewport size
    m_windowMat[0] = width * 0.5f;
    m_windowMat[5] = -height * 0.5f;
    m_windowMat[10] = 1.0f;

    // Translate to viewport center
    m_windowMat[12] = m_viewportRect.left + width * 0.5f;
    m_windowMat[13] = m_viewportRect.top + height * 0.5f;
    m_windowMat[14] = 0.0f;
    m_windowMat[15] = 1.0f;

    // Combine with projection
    EMat4_Multiply(m_combinedMat, m_projMat, m_viewMat);
}

// ============================================================================
// EWindow::CalcClip(void)
// Address: 0x800304A0
// Size: 268 bytes
// NON_MATCHING - calculates clip rect from viewport
// ============================================================================
void EWindow::CalcClip(void)
{
    // Set clip rect to match viewport
    m_clipRect.left = m_viewportRect.left;
    m_clipRect.top = m_viewportRect.top;
    m_clipRect.right = m_viewportRect.right;
    m_clipRect.bottom = m_viewportRect.bottom;

    // Clamp to scissor rect
    if (m_clipRect.left < m_scissorRect.left)
        m_clipRect.left = m_scissorRect.left;
    if (m_clipRect.top < m_scissorRect.top)
        m_clipRect.top = m_scissorRect.top;
    if (m_clipRect.right > m_scissorRect.right)
        m_clipRect.right = m_scissorRect.right;
    if (m_clipRect.bottom > m_scissorRect.bottom)
        m_clipRect.bottom = m_scissorRect.bottom;
}

// ============================================================================
// EWindow::ScaleForScreenshot(bool, int, int, int, int)
// Address: 0x802FFD98
// Size: 376 bytes
// NON_MATCHING - adjusts viewport for hi-res screenshot tiling
// ============================================================================
void EWindow::ScaleForScreenshot(bool enable, int tileX, int tileY, int tilesW, int tilesH)
{
    if (!enable) {
        m_screenshotMode = 0;
        // Restore original viewport
        CalcWindowMat();
        return;
    }

    m_screenshotMode = 1;

    // Calculate tile viewport
    float tileWidth = m_screenWidth / (float)tilesW;
    float tileHeight = m_screenHeight / (float)tilesH;

    float left = tileWidth * (float)tileX;
    float top = tileHeight * (float)tileY;

    // Adjust viewport to render only this tile
    m_viewportRect.left = -left;
    m_viewportRect.top = -top;
    m_viewportRect.right = m_screenWidth - left;
    m_viewportRect.bottom = m_screenHeight - top;

    // Scale projection to match tile
    float scaleX = (float)tilesW;
    float scaleY = (float)tilesH;
    m_projMat[0] *= scaleX;
    m_projMat[5] *= scaleY;

    // Offset projection center
    float offsetX = (2.0f * (float)tileX + 1.0f) / (float)tilesW - 1.0f;
    float offsetY = (2.0f * (float)tileY + 1.0f) / (float)tilesH - 1.0f;
    m_projMat[8] += offsetX;
    m_projMat[9] += offsetY;

    CalcWindowMat();
}

// ============================================================================
// EWindow::Select(ERC*)
// Address: 0x80300040
// Size: 752 bytes
// NON_MATCHING - selects this window as the active render target
// ============================================================================
void EWindow::Select(ERC* rc)
{
    if (!rc) return;

    u8* rcPtr = (u8*)rc;

    // Set view matrix
    ERC_ViewMatrix(rc, m_viewMat, 0, 0.0f);

    // Set projection matrix
    ERC_ProjectionMatrix(rc, m_projMat);

    // Set window matrix
    ERC_WindowMatrix(rc, m_windowMat);

    // Set viewport
    ERC_Viewport(rc, &m_viewportRect);

    // Set scissor
    ERC_Scissor(rc, &m_scissorRect);

    // Set clip rect
    ERC_ClipRect(rc, &m_clipRect);

    // Update combined matrix
    EMat4_Multiply(m_combinedMat, m_projMat, m_viewMat);

    // Set additional render state
    // NON_MATCHING: fog setup, z range, etc.

    // Handle screenshot mode
    if (m_screenshotMode) {
        // Apply screenshot tiling adjustments
        // NON_MATCHING: modified projection for tiled rendering
    }
}
#endif
