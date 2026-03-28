#if 0 // SKIP
// e_window.cpp - EWindow class (window/viewport management)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_window.obj)
//
// Medium functions (65-256 bytes) decompiled from the e_window object file.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERenderSurface;
class E3DWindow;
class ERC;
struct EMat4;

template<typename T>
struct TRect {
    T left, top, right, bottom;
};

struct EVec2 {
    float x, y;
};

// External functions
extern void EWindow_InitHelper(int active, int type);
extern void* __builtin_new(u32 size);
extern void __builtin_delete(void* ptr);
extern void* FastAllocPool_Alloc(void* pool, u32 size);
extern void FastAllocPool_Free(void* pool, void* ptr);

// EWindow class layout (partial)
// 0x00: float m_scaleX
// 0x04-0x13: transform data
// 0x14: float m_scaleY
// 0x18-0x2F: more transform data
// 0x30: float m_offsetX
// 0x34: float m_offsetY
// 0x38-0x5F: more data
// 0x60: float m_clipLeft
// 0x64: float m_clipTop
// 0x68: float m_clipRight
// 0x6C: float m_clipBottom
// 0x70: void* m_vtable

class EWindow {
public:
    float m_scaleX;           // 0x00
    u8 pad04[0x10];           // 0x04
    float m_scaleY;           // 0x14
    u8 pad18[0x18];           // 0x18
    float m_offsetX;          // 0x30
    float m_offsetY;          // 0x34
    u8 pad38[0x28];           // 0x38
    float m_clipLeft;         // 0x60
    float m_clipTop;          // 0x64
    float m_clipRight;        // 0x68
    float m_clipBottom;       // 0x6C
    void* m_vtable;           // 0x70
    u8 pad74[0x20];           // 0x74
    ERenderSurface* m_renderSurface; // 0x94
    u8 pad98[0x10];           // 0x98

    EWindow();
    ~EWindow();

    void SetRenderSurface(ERenderSurface* surface, int param);
    void ScaleOutputRectForScreenshot(TRect<float>* rect);
    void SetOutputCoordinates(TRect<float>& rect);
    void ScaleScissorRectForScreenshot(TRect<float>* rect, TRect<float>* out);
    void CalcClipInv();
    void SetClip(TRect<float>& rect);
    void SetInputCoordinates(TRect<float>& rect);
    void SetRect(TRect<float>& rect);
    int ClipTest(float x, float y);
    int ClipTest(TRect<float>& rect);

    // Virtual functions
    virtual void WindowMatrixChanged() {}
    virtual void InputCoordinatesChanged() {}
    virtual void OutputCoordinatesChanged() {}
    virtual E3DWindow* Cast3DWindow() { return 0; }

    void* operator new(u32 size);
    void operator delete(void* ptr);
};

//=============================================================================
// EWindow::EWindow(void)
// Address: 0x802FFB98, Size: 232
// NON_MATCHING: vtable address, bl targets, float constants
//=============================================================================
// Constructor: initializes transform fields to identity
// scaleX = 1.0, scaleY = 1.0, offsetX = 0.0, offsetY = 0.0
// clip rect = full screen, all flags cleared

//=============================================================================
// EWindow::~EWindow(void)
// Address: 0x802FFC80, Size: 112
// NON_MATCHING: vtable address, bl targets
//=============================================================================
// Destructor: resets vtable, releases resources

//=============================================================================
// EWindow::SetRenderSurface(ERenderSurface*, int)
// Address: 0x802FFCF0, Size: 168
// NON_MATCHING: vtable dispatch, struct offsets
//=============================================================================
// Associates a render surface with this window

//=============================================================================
// EWindow::ScaleOutputRectForScreenshot(TRect<float>*)
// Address: 0x802FFF10, Size: 132
// NON_MATCHING: float math, SDA globals
//=============================================================================
// Scales the output rect for screenshot capture

//=============================================================================
// EWindow::SetOutputCoordinates(TRect<float>&)
// Address: 0x80300710, Size: 200
// NON_MATCHING: float math, vtable dispatch
//=============================================================================
// Sets the output coordinate space from a rectangle

//=============================================================================
// EWindow::ScaleScissorRectForScreenshot(TRect<float>*, TRect<float>*)
// Address: 0x802FFF94, Size: 172
// NON_MATCHING: float math, SDA globals
//=============================================================================
// Scales scissor rect for screenshot capture

//=============================================================================
// EWindow::CalcClipInv(void)
// Address: 0x803005AC, Size: 84
// NON_MATCHING: float reciprocal
//=============================================================================
// Calculates inverse clip values

//=============================================================================
// EWindow::SetClip(TRect<float>&)
// Address: 0x80300600, Size: 72
// NON_MATCHING: float copies
//=============================================================================
// Sets clip rectangle from the given rect
// Copies 4 floats, then calls CalcClipInv

//=============================================================================
// EWindow::SetInputCoordinates(TRect<float>&)
// Address: 0x80300648, Size: 200
// NON_MATCHING: float math, vtable dispatch
//=============================================================================
// Sets input coordinate space from a rectangle

//=============================================================================
// __static_initialization_and_destruction_0 (e_window.obj)
// Address: 0x803007D8, Size: 84
// NON_MATCHING: SDA pattern
//=============================================================================

//=============================================================================
// EWindow::SetRect(TRect<float>&)
// Address: 0x803008DC, Size: 72
// NON_MATCHING: float copies, bl targets
//=============================================================================
// Sets window rect by calling SetInputCoordinates and SetOutputCoordinates

//=============================================================================
// EWindow::ClipTest(float, float)
// Address: 0x80300A3C, Size: 72
// NON_MATCHING: float comparisons
//=============================================================================
// Tests if point (x,y) is within clip rect
// Returns 1 if inside, 0 if outside

//=============================================================================
// EWindow::ClipTest(TRect<float>&)
// Address: 0x80300A84, Size: 100
// NON_MATCHING: float comparisons
//=============================================================================
// Tests if rectangle overlaps clip rect
// Returns 1 if overlapping, 0 if not
#endif
