#ifndef APTCIH_H
#define APTCIH_H

#include "types.h"

// AptCIH - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5ACC (23244 bytes)
// 27 known fields (16 named), 144 methods

class AptCIH {
public:
    // Constructors / Destructors
    AptCIH(AptVirtualFunctionTable_Indices, AptCharacterInst *, AptCIH *)  // 0x806D8454
    ~AptCIH(void);  // 0x806D2D5C

    // Methods
    void isAnimationInst(bool);  // 0x806D9020 (188B)
    void getAnimationInst(void);  // 0x806D8990 (144B)
    void getZombieCount(void);  // 0x806D8424 (48B)
    void getZombieState(void);  // 0x806D8374 (48B)
    void setZombieSate(int);  // 0x806D8340 (52B)
    void isShapeInst(void);  // 0x806D8D70 (172B)
    void isButtonInst(bool);  // 0x806D8CB4 (188B)
    void getNativeHash(void);  // 0x806D36F0 (148B)
    void isSpriteInst(bool);  // 0x806D8B38 (188B)
    void getBoundingRect(AptRect *);  // 0x806D4C9C (364B)
    void isSpriteInstBase(bool);  // 0x806D9188 (188B)
    void isLevelInst(void);  // 0x806D90DC (172B)
    void isTextInst(void);  // 0x806D8E1C (172B)
    void getCharacterInst(void);  // 0x806D8AAC (140B)
    void getSpriteInstBase(void);  // 0x806D86CC (144B)
    void isMorphInst(void);  // 0x806D8F74 (172B)
    void getMorphInst(void);  // 0x806D8874 (140B)
    void getSpriteInst(void);  // 0x806D863C (144B)
    void getRootAnimation(void);  // 0x806D7690 (132B)
    void jumpToFrame(int);  // 0x806D63E0 (572B)
    void getButtonInst(void);  // 0x806D8900 (144B)
    void gotoState(AptCharacterButtonRecordState);  // 0x806D6288 (344B)
    void tick(void);  // 0x806D6FB0 (664B)
    void getTextInst(void);  // 0x806D875C (140B)
    void setProceduralProperty(AptProceduralProperty, float, bool);  // 0x806D544C (2144B)
    void ensureStringAllocated(AptCIH *);  // 0x806D3A2C (1408B)
    void RemoveEventHandler(int);  // 0x806D668C (112B)
    void SetEventHandler(int);  // 0x806D661C (112B)
    bool HasEvent(int);  // 0x806D66FC (292B)
    /* ? */ GetProceduralProperty(AptProceduralProperty);  // 0x806D501C (1072B)
    void ClearCIH(bool);  // 0x806D31C0 (1020B)
    void Remove(void);  // 0x806D2E7C (464B)
    void PreDestroy(void);  // 0x806D304C (140B)
    void DestroyGCPointers(void);  // 0x806D30D8 (232B)
    void queueClipEvents(int, unsigned int, int);  // 0x806D6820 (1936B)
    void setASChanged(int);  // 0x806D82D0 (64B)
    void RegisterReferences(void);  // 0x806D35BC (308B)
    /* ? */ GetNativeHashVirtual(void);  // 0x806D3784 (68B)
    void ContainsNativeHashVirtual(void);  // 0x806D37C8 (84B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806D381C (160B)
    void isCharacterInst(void);  // 0x806D8BF4 (192B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x806D38BC (168B)
    void Release(char *, char *, int);  // 0x806D3964 (200B)
    void deallocAssetStringRecursive(void);  // 0x806D3FAC (244B)
    void render(AptRenderingContext *, AptMath::ClipTransform_t *, AptMaskRenderOperation);  // 0x806D40A0 (2672B)
    void getShapeInst(void);  // 0x806D8A20 (140B)
    void isStaticTextInst(void);  // 0x806D8EC8 (172B)
    void getStaticTextInst(void);  // 0x806D87E8 (140B)
    void _getBoundingRect(AptRenderingContext *, AptRect *);  // 0x806D4B10 (396B)
    void getGlobalBoundingRect(AptRect *);  // 0x806D4E08 (300B)
    void getGlobalTranslation(float *, float *);  // 0x806D4F34 (232B)
    /* ? */ GetCosAngle(AptMatrix *);  // 0x806D9244 (128B)
    /* ? */ GetVectorLength(AptMatrix *);  // 0x806D92C4 (148B)
    void FindAndSetEvents(void);  // 0x806D5CAC (404B)
    void associateInstToClass(void);  // 0x806D5E40 (1096B)
    void SetInCtor(unsigned int);  // 0x806D938C (48B)
    void checkIfHigher(AptCIH *);  // 0x806D7248 (256B)
    void getParentCount(void);  // 0x806D7348 (104B)
    void getDepthOfParentAt(int);  // 0x806D73B0 (244B)
    void isVisiable(void);  // 0x806D74A4 (212B)
    void isParent(AptCIH *);  // 0x806D7578 (204B)
    bool HasMouseEvent(void);  // 0x806D7644 (76B)
    void decZombieCount(void);  // 0x806D7714 (88B)
    void hasRenderData(void);  // 0x806D776C (228B)
    /* ? */ GetMovieclipInfo(AptMovieclipInformation *);  // 0x806D7850 (532B)
    void getHasClass(void);  // 0x806D82A0 (48B)
    void setHasClass(int);  // 0x806D8260 (64B)
    void getASChanged(void);  // 0x806D8310 (48B)
    void incZombieCount(void);  // 0x806D83A4 (128B)
    bool IsInCtor(void);  // 0x806D9358 (52B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_movieclipInfo;  // 0x000 [R/W] (AptCIH, ClearCIH, GetCosAngle, ...)
    s16 m_field_002;  // 0x002 [R] (render)
    f32 m_cosAngle;  // 0x004 [R/W] (GetCosAngle, GetVectorLength, jumpToFrame, ...)
    f32 m_cosAngle_008;  // 0x008 [R/W] (AptCIH, ClearCIH, FindAndSetEvents, ...)
    u32 m_field_00C;  // 0x00C [R/W] (associateInstToClass, getNativeHash, render, ...)
    f32 m_eventHandler;  // 0x010 [R/W] (AptCIH, FindAndSetEvents, GetProceduralProperty, ...)
    f32 m_proceduralProperty;  // 0x014 [R/W] (AptCIH, GetProceduralProperty, setProceduralProperty)
    f32 m_proceduralProperty_018;  // 0x018 [R/W] (AptCIH, GetProceduralProperty, render, ...)
    f32 m_proceduralProperty_01C;  // 0x01C [R/W] (AptCIH, GetProceduralProperty, render, ...)
    f32 m_proceduralProperty_020;  // 0x020 [R/W] (AptCIH, GetProceduralProperty, associateInstToClass, ...)
    f32 m_proceduralProperty_024;  // 0x024 [R/W] (AptCIH, GetProceduralProperty, queueClipEvents, ...)
    f32 m_proceduralProperty_028;  // 0x028 [R/W] (AptCIH, GetProceduralProperty, associateInstToClass, ...)
    f32 m_field_02C;  // 0x02C [R/W] (AptCIH, associateInstToClass)
    f32 m_field_030;  // 0x030 [R/W] (AptCIH, render)
    f32 m_field_034;  // 0x034 [W] (AptCIH)
    f32 m_field_038;  // 0x038 [W] (AptCIH)
    f32 m_proceduralProperty_03C;  // 0x03C [R/W] (AptCIH, GetProceduralProperty, setProceduralProperty)
    f32 m_proceduralProperty_040;  // 0x040 [R/W] (AptCIH, GetProceduralProperty, setProceduralProperty)
    f32 m_proceduralProperty_044;  // 0x044 [R/W] (AptCIH, GetProceduralProperty, setProceduralProperty)
    u32 m_field_048;  // 0x048 [R/W] (AptCIH, DestroyGCPointers, RegisterReferences, ...)
    u32 m_movieclipInfo_04C;  // 0x04C [R/W] (AptCIH, ClearCIH, DestroyGCPointers, ...)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (AptCIH)
    u16 m_proceduralProperty_05C;  // 0x05C [R/W] (AptCIH, ClearCIH, GetProceduralProperty, ...)
    u8 _pad_05E[2];  // 0x05E
    u32 m_proceduralProperty_060;  // 0x060 [R/W] (AptCIH, GetProceduralProperty, setProceduralProperty, ...)
    u8 _pad_064[8];  // 0x064
    u32 m_field_06C;  // 0x06C [W] (deallocAssetStringRecursive)
    u8 _pad_070[0xC];  // 0x070
    u32 m_field_07C;  // 0x07C [R] (render)
    u8 _pad_080[0x5A48];  // 0x080
    f32 m_field_5AC8;  // 0x5AC8 [R] (render)
};

#endif // APTCIH_H
