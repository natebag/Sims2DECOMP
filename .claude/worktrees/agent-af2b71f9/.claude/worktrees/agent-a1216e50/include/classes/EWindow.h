#ifndef EWINDOW_H
#define EWINDOW_H

#include "types.h"

// EWindow - struct layout extracted from assembly analysis
// Estimated minimum size: 0x904 (2308 bytes)
// 31 known fields (7 named), 62 methods

class EWindow {
public:
    // Constructors / Destructors
    EWindow(void)  // 0x807EAF60
    ~EWindow(void);  // 0x807EB074

    // Methods
    void SetClip(TRect<float> &);  // 0x807EBF68 (76B)
    void ScaleForScreenshot(bool, int, int, int, int);  // 0x807EB22C (528B)
    void Select(ERC *);  // 0x807EB6EC (1232B)
    /* ? */ GetCurrent3DWindow(void);  // 0x807ECC0C (44B)
    void SetRenderSurface(ERenderSurface *, int);  // 0x807EB104 (296B)
    /* ? */ GetCurrentWindow(void);  // 0x807ECBE0 (44B)
    void Transform(float, float, float &, float &);  // 0x807EC5FC (248B)
    void TransformInv(float, float, float &, float &);  // 0x807EC824 (248B)
    void InputCoordinatesChanged(void);  // 0x807ECC58 (32B)
    void OutputCoordinatesChanged(void);  // 0x807ECC78 (32B)
    void WindowMatrixChanged(void);  // 0x807ECC38 (32B)
    void CalcWindowMat(void);  // 0x807EBC04 (348B)
    void CalcClip(void);  // 0x807EBD60 (408B)
    void ScaleOutputRectForScreenshot(TRect<float> *);  // 0x807EB43C (320B)
    void SetOutputCoordinates(TRect<float> &);  // 0x807EC050 (156B)
    void ScaleScissorRectForScreenshot(TRect<float> *, TRect<float> *);  // 0x807EB57C (368B)
    void TransformToPixel(EVec2 &, EVec2 &);  // 0x807EBBBC (72B)
    void Transform(EVec2 &, EVec2 &);  // 0x807EC4CC (304B)
    void CalcClipInv(void);  // 0x807EBEF8 (112B)
    void SetInputCoordinates(TRect<float> &);  // 0x807EBFB4 (156B)
    void Cast3DWindow(void);  // 0x807ECC98 (40B)
    void SetInputCoordinatesAndClip(TRect<float> &);  // 0x807EC428 (76B)
    void SetRect(TRect<float> &);  // 0x807EC474 (88B)
    void TransformInv(EVec2 &, EVec2 &);  // 0x807EC6F4 (304B)
    void TransformScale(float, float, float &, float &);  // 0x807EC91C (168B)
    void TransformScale(EVec2 &, EVec2 &);  // 0x807EC9C4 (224B)
    void ClipTest(EVec2 &);  // 0x807ECAA4 (120B)
    void ClipTest(float, float);  // 0x807ECB1C (112B)
    void ClipTest(TRect<float> &);  // 0x807ECB8C (84B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_renderSurface;  // 0x000 [R/W] (CalcClip, CalcClipInv, ScaleOutputRectForScreenshot, ...)
    f32 m_field_004;  // 0x004 [R/W] (ScaleForScreenshot, ScaleOutputRectForScreenshot, ScaleScissorRectForScreenshot)
    f32 m_field_008;  // 0x008 [R/W] (ScaleForScreenshot, ScaleOutputRectForScreenshot, ScaleScissorRectForScreenshot)
    f32 m_field_00C;  // 0x00C [R/W] (ScaleOutputRectForScreenshot, ScaleScissorRectForScreenshot)
    u8 _pad_010[4];  // 0x010
    f32 m_field_014;  // 0x014 [R] (CalcClip, CalcClipInv)
    u8 _pad_018[0x18];  // 0x018
    f32 m_field_030;  // 0x030 [R] (CalcClip, CalcClipInv)
    f32 m_field_034;  // 0x034 [R] (CalcClip, CalcClipInv)
    u8 _pad_038[8];  // 0x038
    f32 m_inputCoordinates;  // 0x040 [R/W] (CalcWindowMat, EWindow, SetInputCoordinates)
    f32 m_field_044;  // 0x044 [R] (CalcWindowMat)
    f32 m_field_048;  // 0x048 [R] (CalcWindowMat)
    u8 _pad_04C[4];  // 0x04C
    f32 m_outputCoordinates;  // 0x050 [R/W] (CalcClip, CalcWindowMat, EWindow, ...)
    f32 m_field_054;  // 0x054 [R] (CalcClip, CalcWindowMat)
    f32 m_field_058;  // 0x058 [R] (CalcClip, CalcWindowMat)
    f32 m_field_05C;  // 0x05C [R] (CalcClip)
    f32 m_clip;  // 0x060 [R/W] (CalcClip, CalcClipInv, ClipTest, ...)
    f32 m_field_064;  // 0x064 [R/W] (CalcClip, CalcClipInv, ClipTest)
    f32 m_field_068;  // 0x068 [R/W] (CalcClip, CalcClipInv, ClipTest)
    f32 m_field_06C;  // 0x06C [R/W] (CalcClip, CalcClipInv, ClipTest)
    f32 m_field_070;  // 0x070 [R/W] (CalcClip, CalcClipInv)
    f32 m_field_074;  // 0x074 [R/W] (CalcClip, CalcClipInv)
    f32 m_field_078;  // 0x078 [R/W] (CalcClip, CalcClipInv)
    f32 m_field_07C;  // 0x07C [R/W] (CalcClip, CalcClipInv)
    f32 m_field_080;  // 0x080 [R/W] (CalcClip, Select)
    f32 m_field_084;  // 0x084 [W] (CalcClip)
    f32 m_field_088;  // 0x088 [W] (CalcClip)
    f32 m_field_08C;  // 0x08C [W] (CalcClip)
    u32 m_renderSurface_090;  // 0x090 [R/W] (EWindow, Select, SetRenderSurface)
    u32 m_renderSurface_094;  // 0x094 [R/W] (EWindow, Select, SetRenderSurface)
    u32 m_field_098;  // 0x098 [R/W] (EWindow, Select)
    u32 m_outputCoordinates_09C;  // 0x09C [R/W] (CalcWindowMat, EWindow, Select, ...)
    u8 _pad_0A0[0x860];  // 0x0A0
    u32 m_field_900;  // 0x900 [W] (ScaleForScreenshot)
};

#endif // EWINDOW_H
