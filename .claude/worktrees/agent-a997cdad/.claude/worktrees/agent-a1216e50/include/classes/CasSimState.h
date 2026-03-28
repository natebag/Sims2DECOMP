#ifndef CASSIMSTATE_H
#define CASSIMSTATE_H

#include "types.h"

// CasSimState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x120 (288 bytes)
// 72 known fields (47 named), 50 methods

class CasSimState {
public:
    // Constructors / Destructors
    CasSimState(void)  // 0x8046FB5C
    CasSimState(CasSimDescriptionS2C &)  // 0x8046FBC0
    ~CasSimState(void);  // 0x8046FCC8

    // Methods
    /* ? */ GetSimDescription(void);  // 0x80475FCC (44B)
    /* ? */ GetAdjacentIndex(unsigned char, bool);  // 0x8046FD34 (3400B)
    /* ? */ GetNextAvailableSleeveStyle(eBodyPartS2C, signed char, bool, CasSimPartsS2C &);  // 0x804719EC (1240B)
    /* ? */ GetNextAvailableMidLayerTorsoStyle(signed char, bool, CasSimPartsS2C &);  // 0x804720EC (288B)
    /* ? */ GetNextAvailableMidLayerCollarStyle(signed char, CasSimPartsS2C &);  // 0x804723BC (284B)
    /* ? */ GetNextAvailableOuterLayerTorsoStyle(signed char, CasSimPartsS2C &);  // 0x804724D8 (284B)
    /* ? */ GetNextAvailableOuterLayerCollarStyle(signed char, bool, CasSimPartsS2C &);  // 0x804725F4 (288B)
    /* ? */ GetNextAvailableLowerBodyStyle(signed char, bool, CasSimPartsS2C &);  // 0x80472714 (288B)
    /* ? */ GetNextAvailableHairStyle(signed char, bool, CasSimPartsS2C &);  // 0x80472834 (752B)
    /* ? */ GetNextAvailableHatStyle(signed char, bool, CasSimPartsS2C &);  // 0x80472B24 (288B)
    /* ? */ GetNextAvailableArmAccessoryStyle(signed char, bool, CasSimPartsS2C &);  // 0x80472C44 (288B)
    /* ? */ GetMoreThanOneOption(unsigned char);  // 0x80470A7C (3952B)
    /* ? */ GetNextSleeveStyle(eBodyPartS2C, Sim::SleeveStyleS2C, bool);  // 0x80471EC4 (552B)
    /* ? */ GetNextMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, bool);  // 0x8047220C (432B)
    /* ? */ GetNextBodyPartStyle(int, int, bool);  // 0x80472D64 (316B)
    void HandleEventInitSim(CasEventInitSim &);  // 0x80472EA0 (252B)
    void HandleEventResetSim(CasEventResetSim &);  // 0x80472F9C (348B)
    void HandleEventStoreSim(CasEventStoreSim &);  // 0x804730F8 (124B)
    void HandleEventChangeSim(CasEventChangeSimS2C &);  // 0x80473174 (2848B)
    void HandleEventMorphSim(CasEventMorphSimS2C &);  // 0x80473C94 (404B)
    void SetSimName(unsigned wchar_t *, unsigned wchar_t *);  // 0x80473E28 (144B)
    /* ? */ GetStoredSimDescription(void);  // 0x80475FF8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CasSimState, HandleEventChangeSim, HandleEventInitSim, ...)
    u32 m_field_004;  // 0x004 [W] (CasSimState, HandleEventInitSim, HandleEventStoreSim)
    u32 m_field_008;  // 0x008 [W] (HandleEventInitSim, HandleEventStoreSim)
    u32 m_field_00C;  // 0x00C [W] (HandleEventInitSim, HandleEventStoreSim)
    u32 m_field_010;  // 0x010 [W] (HandleEventInitSim, HandleEventStoreSim)
    u32 m_field_014;  // 0x014 [W] (HandleEventInitSim, HandleEventStoreSim)
    u8 _pad_018[0x32];  // 0x018
    u16 m_simName;  // 0x04A [W] (SetSimName)
    u8 _pad_04C[0x40];  // 0x04C
    u32 m_moreThanOneOption;  // 0x08C [R] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim, ...)
    u8 m_adjacentIndex;  // 0x090 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_adjacentIndex_091;  // 0x091 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_moreThanOneOption_092;  // 0x092 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_093;  // 0x093 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_adjacentIndex_094;  // 0x094 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_moreThanOneOption_095;  // 0x095 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_096;  // 0x096 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_097[1];  // 0x097
    u32 m_moreThanOneOption_098;  // 0x098 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_09B;  // 0x09B [R] (HandleEventChangeSim)
    u32 m_field_09C;  // 0x09C [W] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0A0;  // 0x0A0 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0A1;  // 0x0A1 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0A2[6];  // 0x0A2
    u32 m_moreThanOneOption_0A8;  // 0x0A8 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0AB;  // 0x0AB [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0AC;  // 0x0AC [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0AD;  // 0x0AD [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0AE[2];  // 0x0AE
    u32 m_moreThanOneOption_0B0;  // 0x0B0 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0B3;  // 0x0B3 [R] (HandleEventChangeSim)
    u32 m_moreThanOneOption_0B4;  // 0x0B4 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0B7;  // 0x0B7 [R] (HandleEventChangeSim)
    u32 m_moreThanOneOption_0B8;  // 0x0B8 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0BB;  // 0x0BB [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0BC;  // 0x0BC [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0BD;  // 0x0BD [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0BE[2];  // 0x0BE
    u32 m_moreThanOneOption_0C0;  // 0x0C0 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0C3;  // 0x0C3 [R] (HandleEventChangeSim)
    u32 m_moreThanOneOption_0C4;  // 0x0C4 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0C7;  // 0x0C7 [R] (HandleEventChangeSim)
    u32 m_moreThanOneOption_0C8;  // 0x0C8 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0CB;  // 0x0CB [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0CC;  // 0x0CC [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0CD;  // 0x0CD [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0CE[2];  // 0x0CE
    u32 m_moreThanOneOption_0D0;  // 0x0D0 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0D3;  // 0x0D3 [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0D4;  // 0x0D4 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0D5;  // 0x0D5 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0D6[6];  // 0x0D6
    u8 m_adjacentIndex_0DC;  // 0x0DC [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_moreThanOneOption_0DD;  // 0x0DD [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0DE;  // 0x0DE [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0DF[1];  // 0x0DF
    u32 m_moreThanOneOption_0E0;  // 0x0E0 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0E3;  // 0x0E3 [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0E4;  // 0x0E4 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0E5;  // 0x0E5 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0E6[2];  // 0x0E6
    u32 m_adjacentIndex_0E8;  // 0x0E8 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u32 m_adjacentIndex_0EC;  // 0x0EC [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_moreThanOneOption_0F0;  // 0x0F0 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0F1;  // 0x0F1 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_moreThanOneOption_0F2;  // 0x0F2 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0F3;  // 0x0F3 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u32 m_moreThanOneOption_0F4;  // 0x0F4 [R/W] (GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_field_0F7;  // 0x0F7 [R] (HandleEventChangeSim)
    u8 m_moreThanOneOption_0F8;  // 0x0F8 [R/W] (GetAdjacentIndex, GetMoreThanOneOption, HandleEventChangeSim)
    u8 m_adjacentIndex_0F9;  // 0x0F9 [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_adjacentIndex_0FA;  // 0x0FA [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_adjacentIndex_0FB;  // 0x0FB [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 m_adjacentIndex_0FC;  // 0x0FC [R/W] (GetAdjacentIndex, HandleEventChangeSim)
    u8 _pad_0FD[3];  // 0x0FD
    f32 m_field_100;  // 0x100 [W] (HandleEventMorphSim)
    f32 m_field_104;  // 0x104 [W] (HandleEventMorphSim)
    f32 m_field_108;  // 0x108 [W] (HandleEventMorphSim)
    f32 m_field_10C;  // 0x10C [W] (HandleEventMorphSim)
    f32 m_field_110;  // 0x110 [W] (HandleEventMorphSim)
    f32 m_field_114;  // 0x114 [W] (HandleEventMorphSim)
    f32 m_field_118;  // 0x118 [W] (HandleEventMorphSim)
    f32 m_field_11C;  // 0x11C [W] (HandleEventMorphSim)
};

#endif // CASSIMSTATE_H
