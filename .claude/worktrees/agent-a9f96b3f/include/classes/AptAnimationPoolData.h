#ifndef APTANIMATIONPOOLDATA_H
#define APTANIMATIONPOOLDATA_H

#include "types.h"

// AptAnimationPoolData - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 38 known fields (1 named), 68 methods

class AptAnimationPoolData {
public:
    // Constructors / Destructors
    AptAnimationPoolData(AptInitParmsT &)  // 0x806C11DC
    ~AptAnimationPoolData(void);  // 0x806C15CC

    // Methods
    /* ? */ GetMaxIntervalTimers(void);  // 0x806BCA04 (44B)
    void PreDestroy(void);  // 0x806C175C (912B)
    void Reset(void);  // 0x806C1AEC (136B)
    void tickIntervalTimers(int);  // 0x806C1B74 (1172B)
    void runActions(void);  // 0x806C21E0 (1192B)
    void addInput(unsigned int);  // 0x806C2738 (236B)
    void clearBIL(void);  // 0x806C2AC8 (204B)
    void addInput(AptInputType, AptInputState, AptInputController);  // 0x806C2824 (132B)
    void addAnalogInput(AptAnalogStickInfo);  // 0x806C2688 (176B)
    void setInputMask(AptCIH *);  // 0x806C2DF4 (44B)
    void RegisterReferences(void);  // 0x806C3558 (1148B)
    void _tickNewInsts(void);  // 0x806C2008 (472B)
    /* ? */ GetActionPool(void);  // 0x806C5028 (44B)
    void removeTimerFunctions(AptCIH *);  // 0x806C28A8 (544B)
    void appendButtonToBIL(AptCIH *, AptMatrix *);  // 0x806C2B94 (240B)
    void removeFromBIL(AptCIH *);  // 0x806C2C84 (368B)
    void isInputMasked(AptCIH *);  // 0x806C2E20 (132B)
    void addActionFront(AptActionBlock *, AptCIH *, int, unsigned int);  // 0x806D80F8 (100B)
    void addActionBack(AptActionBlock *, AptCIH *, int, unsigned int);  // 0x806D8094 (100B)
    void addFunctionBack(AptCIH *, AptValue *, int, int, unsigned int);  // 0x806D815C (108B)
    void addFunctionFront(AptCIH *, AptValue *, int, int, unsigned int);  // 0x806D81C8 (108B)
    /* ? */ GetMaxNewMovieClips(void);  // 0x806E41EC (44B)
    void setValidFocusButton(void);  // 0x806E6A60 (632B)
    void ProcessInputs(void);  // 0x806E8860 (160B)
    void validateBIL(void);  // 0x806E8700 (352B)
    void _doButtonActions(AptCIH *, int);  // 0x806E65DC (1156B)
    void _isPointInButtonHitTestRegion(AptCharacterButton *, AptMatrix *, int, int);  // 0x806E6F1C (704B)
    void ProcessInputSet(AptInputType, AptInputState, unsigned int, AptInputController, bool);  // 0x806E71DC (1312B)
    void _pointHits(AptCIH *, unsigned int);  // 0x806E76FC (304B)
    void ProcessListenerEvents(AptInputType, AptInputState, unsigned int, AptInputController);  // 0x806E782C (468B)
    void AddListenerToQueue(AptValue *, int, unsigned int);  // 0x806E7A00 (1092B)
    void HandleFocusButton(AptInputType, AptInputState, AptCIH **);  // 0x806E7E44 (1352B)
    void HandleAutoNav(AptCIH *, AptInputType, AptInputState);  // 0x806E838C (500B)
    void ProcessAptInput(unsigned int, bool);  // 0x806E8580 (384B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddListenerToQueue, AptAnimationPoolData, HandleFocusButton, ...)
    u16 m_field_002;  // 0x002 [R/W] (AptAnimationPoolData)
    u32 m_field_004;  // 0x004 [R/W] (AptAnimationPoolData, RegisterReferences, _tickNewInsts, ...)
    u16 m_field_008;  // 0x008 [R/W] (AddListenerToQueue, AptAnimationPoolData, HandleAutoNav, ...)
    u16 m_field_00A;  // 0x00A [R] (PreDestroy)
    u32 m_field_00C;  // 0x00C [R] (PreDestroy, ProcessInputSet, RegisterReferences, ...)
    u32 m_field_010;  // 0x010 [R/W] (AddListenerToQueue, AptAnimationPoolData, RegisterReferences, ...)
    u32 m_field_014;  // 0x014 [R/W] (AptAnimationPoolData, RegisterReferences, appendButtonToBIL, ...)
    u16 m_field_018;  // 0x018 [R/W] (AptAnimationPoolData, ProcessListenerEvents, ~AptAnimationPoolData)
    u8 _pad_01A[2];  // 0x01A
    u32 m_field_01C;  // 0x01C [R] (PreDestroy, ProcessListenerEvents, RegisterReferences)
    u16 m_field_020;  // 0x020 [R/W] (AptAnimationPoolData, ProcessInputSet, ~AptAnimationPoolData)
    u8 _pad_022[2];  // 0x022
    u32 m_field_024;  // 0x024 [R] (AddListenerToQueue, HandleFocusButton, ProcessInputSet, ...)
    u32 m_field_028;  // 0x028 [R/W] (AddListenerToQueue, RegisterReferences)
    u32 m_field_02C;  // 0x02C [R/W] (AptAnimationPoolData, PreDestroy, RegisterReferences, ...)
    u32 m_field_030;  // 0x030 [R/W] (AptAnimationPoolData, PreDestroy, removeTimerFunctions, ...)
    u32 m_field_034;  // 0x034 [R/W] (AptAnimationPoolData, ProcessInputs, addInput)
    u32 m_field_038;  // 0x038 [R/W] (AptAnimationPoolData, ProcessInputs, addInput, ...)
    u32 m_field_03C;  // 0x03C [W] (AptAnimationPoolData)
    u8 _pad_040[0xC];  // 0x040
    u32 m_field_04C;  // 0x04C [R] (HandleFocusButton, _tickNewInsts, runActions)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [W] (AptAnimationPoolData)
    u16 m_field_05C;  // 0x05C [R/W] (AddListenerToQueue, AptAnimationPoolData)
    u8 _pad_05E[2];  // 0x05E
    u32 m_field_060;  // 0x060 [W] (AptAnimationPoolData)
    u32 m_field_064;  // 0x064 [R/W] (AptAnimationPoolData, HandleAutoNav, HandleFocusButton, ...)
    u32 m_field_068;  // 0x068 [R/W] (AptAnimationPoolData, HandleAutoNav)
    u32 m_field_06C;  // 0x06C [R/W] (AptAnimationPoolData, _pointHits)
    u32 m_field_070;  // 0x070 [R/W] (AptAnimationPoolData, _pointHits)
    f32 m_field_074;  // 0x074 [W] (addAnalogInput)
    f32 m_field_078;  // 0x078 [W] (addAnalogInput)
    u8 m_field_07C;  // 0x07C [W] (addAnalogInput)
    u8 _pad_07D[7];  // 0x07D
    f32 m_field_084;  // 0x084 [W] (addAnalogInput)
    f32 m_field_088;  // 0x088 [W] (addAnalogInput)
    u8 m_field_08C;  // 0x08C [W] (addAnalogInput)
    u8 _pad_08D[7];  // 0x08D
    u32 m_field_094;  // 0x094 [R/W] (AptAnimationPoolData, RegisterReferences)
    u32 m_field_098;  // 0x098 [R/W] (AptAnimationPoolData, RegisterReferences, runActions, ...)
    u32 m_field_09C;  // 0x09C [R/W] (AptAnimationPoolData, ~AptAnimationPoolData)
    u32 m_field_0A0;  // 0x0A0 [R/W] (AptAnimationPoolData, RegisterReferences)
    u32 m_field_0A4;  // 0x0A4 [R/W] (AptAnimationPoolData, addInput, ~AptAnimationPoolData)
    u32 m_field_0A8;  // 0x0A8 [R/W] (AptAnimationPoolData)
};

#endif // APTANIMATIONPOOLDATA_H
