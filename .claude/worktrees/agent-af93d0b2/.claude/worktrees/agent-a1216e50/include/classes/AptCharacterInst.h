#ifndef APTCHARACTERINST_H
#define APTCHARACTERINST_H

#include "types.h"

// AptCharacterInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x78 (120 bytes)
// 23 known fields (0 named), 78 methods

class AptCharacterInst {
public:
    // Constructors / Destructors
    AptCharacterInst(void)  // 0x806D215C
    ~AptCharacterInst(void);  // 0x806D21D0

    // Methods
    /* ? */ GetNativeHash(void);  // 0x806BC9D8 (44B)
    void DestroyGCPointers(void);  // 0x806C4B40 (76B)
    void CleanNativeFunctions(void);  // 0x806CA8EC (2648B)
    void SetNativeHash(AptNativeHash *);  // 0x806D227C (40B)
    void _gotoAndX(AptValue *, int, int);  // 0x806CA73C (432B)
    void sMethod_gotoAndStop(AptValue *, int);  // 0x806CB344 (80B)
    void sMethod_gotoAndPlay(AptValue *, int);  // 0x806CB394 (80B)
    void sMethod_attachMovie(AptValue *, int);  // 0x806CB3E4 (724B)
    void sMethod_loadMovie(AptValue *, int);  // 0x806CB6B8 (672B)
    void sMethod_unloadMovie(AptValue *, int);  // 0x806CB958 (288B)
    void sMethod_duplicateMovieClip(AptValue *, int);  // 0x806CBA78 (256B)
    void sMethod_removeMovieClip(AptValue *, int);  // 0x806CBB78 (224B)
    void sMethod_removeTextField(AptValue *, int);  // 0x806CBC58 (224B)
    void sMethod_createTextField(AptValue *, int);  // 0x806CBD38 (1272B)
    void sMethod_getDepth(AptValue *, int);  // 0x806CC230 (136B)
    void sMethod_swapDepths(AptValue *, int);  // 0x806CC2B8 (1052B)
    void sMethod_setMask(AptValue *, int);  // 0x806CC6D4 (412B)
    void sMethod_getBounds(AptValue *, int);  // 0x806CC870 (516B)
    void sMethod_startDrag(AptValue *, int);  // 0x806CCA74 (720B)
    void sMethod_hitTest(AptValue *, int);  // 0x806CCD44 (704B)
    void sMethod_createEmptyMovieClip(AptValue *, int);  // 0x806CD004 (624B)
    void sMethod_loadVariables(AptValue *, int);  // 0x806CD274 (172B)
    void sMethod_stop(AptValue *, int);  // 0x806CD320 (148B)
    void sMethod_play(AptValue *, int);  // 0x806CD3B4 (148B)
    void sMethod_nextFrame(AptValue *, int);  // 0x806CD448 (172B)
    void sMethod_prevFrame(AptValue *, int);  // 0x806CD4F4 (172B)
    void sMethod_getBytesTotal(AptValue *, int);  // 0x806CD5A0 (532B)
    void sMethod_getBytesLoaded(AptValue *, int);  // 0x806CD7B4 (464B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x806CD984 (5104B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806CED74 (8268B)
    void sMethod_localToGlobal(AptValue *, int);  // 0x806D18E0 (552B)
    void sMethod_getTextFormat(AptValue *, int);  // 0x806D1460 (1152B)
    void sMethod_getNewTextFormat(AptValue *, int);  // 0x806D10E0 (896B)
    void sMethod_setTextFormat(AptValue *, int);  // 0x806D0DC0 (800B)
    void PreDestroy(void);  // 0x806D21B0 (32B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (objectMemberLookup, objectMemberSet, sMethod_createEmptyMovieClip, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup, objectMemberSet)
    f32 m_field_004;  // 0x004 [R/W] (objectMemberLookup, objectMemberSet, sMethod_createEmptyMovieClip, ...)
    f32 m_field_008;  // 0x008 [R/W] (objectMemberLookup, objectMemberSet, sMethod_createEmptyMovieClip, ...)
    f32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, objectMemberSet, sMethod_createEmptyMovieClip, ...)
    f32 m_field_010;  // 0x010 [R/W] (objectMemberLookup, objectMemberSet, sMethod_createEmptyMovieClip, ...)
    f32 m_field_014;  // 0x014 [R/W] (sMethod_createTextField, sMethod_getNewTextFormat, sMethod_getTextFormat, ...)
    u32 m_field_018;  // 0x018 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getNewTextFormat, ...)
    u32 m_field_01C;  // 0x01C [R/W] (_gotoAndX, objectMemberLookup, sMethod_createTextField, ...)
    f32 m_field_020;  // 0x020 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getBounds, ...)
    f32 m_field_024;  // 0x024 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getBounds, ...)
    f32 m_field_028;  // 0x028 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getNewTextFormat, ...)
    u32 m_field_02C;  // 0x02C [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getNewTextFormat, ...)
    u32 m_field_030;  // 0x030 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getNewTextFormat, ...)
    u32 m_field_034;  // 0x034 [R/W] (objectMemberLookup, sMethod_createTextField, sMethod_getTextFormat)
    u32 m_field_038;  // 0x038 [R/W] (objectMemberLookup, sMethod_createTextField)
    u8 _pad_03C[8];  // 0x03C
    f32 m_field_044;  // 0x044 [R] (objectMemberLookup)
    f32 m_field_048;  // 0x048 [R] (objectMemberLookup, objectMemberSet, sMethod_localToGlobal, ...)
    u32 m_field_04C;  // 0x04C [R] (_gotoAndX, objectMemberLookup, objectMemberSet, ...)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (sMethod_getDepth, sMethod_setMask, sMethod_swapDepths)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (sMethod_getTextFormat)
    u32 m_field_06C;  // 0x06C [R] (objectMemberLookup)
    u8 _pad_070[4];  // 0x070
    u32 m_field_074;  // 0x074 [R] (objectMemberLookup)
};

#endif // APTCHARACTERINST_H
