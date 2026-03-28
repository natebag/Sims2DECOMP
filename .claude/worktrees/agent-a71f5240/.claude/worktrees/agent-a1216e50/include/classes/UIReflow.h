#ifndef UIREFLOW_H
#define UIREFLOW_H

#include "types.h"

// UIReflow - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (2 named), 98 methods

class UIReflow {
public:
    // Constructors / Destructors
    UIReflow(void)  // 0x8048F104
    ~UIReflow(void);  // 0x8048F154

    // Methods
    void SetFocus(UIScreenID);  // 0x8048F1E0 (192B)
    void ResetSize(char *, int, int, int);  // 0x8048F2A0 (492B)
    void ResetPosition(char *, int, int, int);  // 0x8048F48C (492B)
    void ResetZ(char *, int, int);  // 0x8048F678 (400B)
    void ResetVisibility(char *, bool, int);  // 0x8048F808 (400B)
    void ResetAlpha(char *, unsigned int, int);  // 0x8048F998 (424B)
    void ResetText(char *, char *, int);  // 0x8048FB40 (368B)
    void ResetColorOverride(char *, unsigned int, int);  // 0x8048FCB0 (556B)
    void ResetFontSizeOverride(char *, unsigned int, int);  // 0x8048FEDC (400B)
    void ResetSwfAnimation(char *, char *, int);  // 0x8049006C (368B)
    void ResetSwfFileName(char *, char *, int);  // 0x804901DC (368B)
    void AddToBlock(char *);  // 0x8049034C (352B)
    void ReallocateBlock(void);  // 0x804904AC (420B)
    void OpenTweenBlock(char *, unsigned int, unsigned int, char *, int);  // 0x80490650 (800B)
    void SubmitTweenBlock(void);  // 0x80490970 (356B)
    void Tween_X(int);  // 0x80490AD4 (128B)
    void Tween_Y(int);  // 0x80490B54 (128B)
    void Tween_Z(unsigned int);  // 0x80490BD4 (128B)
    void Tween_H(unsigned int);  // 0x80490C54 (128B)
    void Tween_W(unsigned int);  // 0x80490CD4 (128B)
    void Tween_XScale(float);  // 0x80490D54 (148B)
    void Tween_YScale(float);  // 0x80490DE8 (148B)
    void Tween_Rotation(float);  // 0x80490E7C (136B)
    void Tween_Alpha(unsigned int);  // 0x80490F04 (152B)
    void Tween_ColorOverride(unsigned int);  // 0x80490F9C (180B)
    void Tween_ColorOnlyOverride(unsigned int);  // 0x80491050 (144B)
    void Tween_FontSizeOverride(unsigned int);  // 0x804910E0 (128B)
    void OpenReflowBlock(void);  // 0x80491160 (364B)
    void SubmitReflowBlock(void);  // 0x804912CC (356B)
    void Reflow_Id(char *, int);  // 0x80491430 (284B)
    void Reflow_X(int);  // 0x8049154C (160B)
    void Reflow_Y(int);  // 0x804915EC (160B)
    void Reflow_Z(unsigned int);  // 0x8049168C (160B)
    void Reflow_H(unsigned int);  // 0x8049172C (160B)
    void Reflow_W(unsigned int);  // 0x804917CC (160B)
    void Reflow_XScale(float);  // 0x8049186C (160B)
    void Reflow_YScale(float);  // 0x8049190C (160B)
    void Reflow_Rotation(float);  // 0x804919AC (160B)
    void Reflow_Visibility(bool);  // 0x80491A4C (248B)
    void Reflow_Alpha(unsigned int);  // 0x80491B44 (160B)
    void Reflow_StringChange(char *);  // 0x80491BE4 (192B)
    void Reflow_ColorOverride(unsigned int);  // 0x80491CA4 (160B)
    void Reflow_ColorOnlyOverride(unsigned int);  // 0x80491D44 (160B)
    void Reflow_FontSizeOverride(unsigned int);  // 0x80491DE4 (160B)
    void Reflow_SwfAnimation(char *);  // 0x80491E84 (96B)
    void Reflow_SwfFile(char *);  // 0x80491EE4 (96B)
    void Debug_PrintBlock(void);  // 0x80491F44 (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddToBlock, OpenReflowBlock, OpenTweenBlock, ...)
    u32 m_focus;  // 0x004 [R/W] (AddToBlock, OpenReflowBlock, OpenTweenBlock, ...)
    u32 m_field_008;  // 0x008 [R/W] (OpenReflowBlock, OpenTweenBlock, ReallocateBlock)
    u32 m_field_00C;  // 0x00C [R/W] (AddToBlock, OpenReflowBlock, OpenTweenBlock, ...)
    u32 m_field_010;  // 0x010 [R/W] (AddToBlock, OpenReflowBlock, OpenTweenBlock)
};

#endif // UIREFLOW_H
