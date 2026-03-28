#ifndef CASSIMDESCRIPTIONS2C_H
#define CASSIMDESCRIPTIONS2C_H

#include "types.h"

// CasSimDescriptionS2C - struct layout extracted from assembly analysis
// Estimated minimum size: 0x122 (290 bytes)
// 74 known fields (38 named), 77 methods

class CasSimDescriptionS2C {
public:
    // Constructors / Destructors
    CasSimDescriptionS2C(bool)  // 0x8044AAD8
    CasSimDescriptionS2C(void)  // 0x8044A750
    ~CasSimDescriptionS2C(void);  // 0x800B1838

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x8044BC8C (1580B)
    void Verify(void);  // 0x8044C490 (5224B)
    /* ? */ GetBodyPartParam(eBodyPartS2C);  // 0x8044B568 (676B)
    /* ? */ GetBodyPartIndex(eBodyPartS2C);  // 0x8044ABF8 (560B)
    /* ? */ GetCompositeTextureID(char *, eSimPartsMapLocation);  // 0x8044F570 (140B)
    /* ? */ GetCompositeTextureName(char *, eSimPartsMapLocation);  // 0x8044F5FC (448B)
    void SetBodyPartIndex(eBodyPartS2C, signed char);  // 0x8044AE28 (508B)
    /* ? */ GetBodyPartTextureIndex(eBodyPartS2C);  // 0x8044B024 (748B)
    void InitializeToDefaultCostume(bool);  // 0x8044F4D8 (152B)
    void ClearSim(bool);  // 0x8044A794 (836B)
    void SetBodyTypeMorphValues(void);  // 0x8044F2EC (492B)
    void SetBodyPartTextureIndex(eBodyPartS2C, signed char);  // 0x8044B310 (600B)
    void SwitchInnerLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044E4AC (452B)
    void InnerLayerHalfTorsoRequired(CasSimPartsS2C &);  // 0x8044E3F0 (188B)
    void SwitchInnerLayerTorso(bool);  // 0x8044E25C (76B)
    void SwitchLowerBodyToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044EE38 (464B)
    void SwitchHatToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044F008 (464B)
    void SetShoeBoottopDisplayedFlag(CasSimPartsS2C &);  // 0x8044F2A4 (72B)
    void WriteSimDescriptionToTextFile(__sFILE *, SimModel *);  // 0x8044F8D4 (6316B)
    void ReadOldDescription(ReconBuffer *);  // 0x8044B80C (1152B)
    void AssertWithInfo(char *);  // 0x8044C2B8 (472B)
    void VerifyBodyPartWithNoOptions(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char &, signed char, signed char, bool);  // 0x8044DA8C (852B)
    void VerifyBodyPartNoTexture(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char, bool);  // 0x8044D8F8 (404B)
    void VerifyBodyPartWithOneOption(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char &, signed char &, signed char, signed char, signed char, bool);  // 0x8044DDE0 (1044B)
    /* ? */ GetHairBodyPart(void);  // 0x8044F7BC (280B)
    void SetInnerLayerTorsoStyle(CasSimPartsS2C &);  // 0x8044E1F4 (104B)
    void SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C &);  // 0x8044E38C (100B)
    void ShouldBootTopBeDisplayed(CasSimPartsS2C &);  // 0x8044F1D8 (204B)
    void SwitchMidLayerTorso(bool);  // 0x8044E2A8 (228B)
    void MidLayerHalfTorsoRequired(CasSimPartsS2C &);  // 0x8044E670 (188B)
    void SwitchMidLayerTorsoToFirstAvailableStyle(CasSimPartsS2C &, bool);  // 0x8044E72C (528B)
    void SwitchMidLayerCollarToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044E93C (212B)
    void SwitchMidLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044EA10 (284B)
    void SwitchOuterLayerTorsoToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044EB2C (212B)
    void SwitchOuterLayerCollarToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044EC00 (356B)
    void SwitchOuterLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &);  // 0x8044ED64 (212B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_bodyPartParam;  // 0x000 [R/W] (ClearSim, DoStream, GetBodyPartParam, ...)
    u8 m_field_002;  // 0x002 [R/W] (ClearSim, DoStream)
    u8 _pad_003[1];  // 0x003
    u16 m_bodyPartParam_004;  // 0x004 [W] (GetBodyPartParam, ReadOldDescription)
    u8 _pad_006[2];  // 0x006
    u32 m_bodyPartParam_008;  // 0x008 [W] (GetBodyPartParam)
    u32 m_bodyPartParam_00C;  // 0x00C [W] (GetBodyPartParam)
    u8 _pad_010[0x32];  // 0x010
    u16 m_field_042;  // 0x042 [W] (ClearSim, Verify)
    u8 _pad_044[0x3E];  // 0x044
    u16 m_field_082;  // 0x082 [W] (ClearSim, Verify)
    u32 m_bodyTypeMorphValues;  // 0x084 [R/W] (CasSimDescriptionS2C, ClearSim, InitializeToDefaultCostume, ...)
    u8 m_bodyTypeMorphValues_088;  // 0x088 [R/W] (ClearSim, SetBodyTypeMorphValues, Verify)
    u8 m_field_089;  // 0x089 [R/W] (ClearSim, Verify)
    u8 m_bodyPartIndex;  // 0x08A [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex;  // 0x08B [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 m_bodyPartIndex_08C;  // 0x08C [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartIndex_08D;  // 0x08D [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex_08E;  // 0x08E [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_08F[1];  // 0x08F
    u32 m_hairBodyPart;  // 0x090 [R/W] (ClearSim, DoStream, GetHairBodyPart)
    u8 m_field_093;  // 0x093 [R] (DoStream)
    u32 m_hairBodyPart_094;  // 0x094 [R/W] (ClearSim, GetHairBodyPart, Verify)
    u8 m_bodyPartIndex_098;  // 0x098 [R/W] (ClearSim, GetBodyPartIndex, InitializeToDefaultCostume, ...)
    u8 m_bodyPartTextureIndex_099;  // 0x099 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex, ...)
    u8 _pad_09A[2];  // 0x09A
    u32 m_innerLayerTorsoStyle;  // 0x09C [R/W] (ClearSim, DoStream, SetInnerLayerTorsoStyle, ...)
    u8 m_field_09F;  // 0x09F [R] (DoStream)
    u32 m_field_0A0;  // 0x0A0 [R/W] (ClearSim, DoStream, SwitchInnerLayerSleeveToFirstAvailableStyle, ...)
    u8 m_field_0A3;  // 0x0A3 [R] (DoStream)
    u8 m_bodyPartIndex_0A4;  // 0x0A4 [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex, ...)
    u8 m_bodyPartTextureIndex_0A5;  // 0x0A5 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex, ...)
    u8 _pad_0A6[2];  // 0x0A6
    u32 m_field_0A8;  // 0x0A8 [R/W] (ClearSim, DoStream, SwitchMidLayerTorso, ...)
    u8 m_field_0AB;  // 0x0AB [R] (DoStream)
    u32 m_field_0AC;  // 0x0AC [R/W] (ClearSim, DoStream, SwitchMidLayerCollarToFirstAvailableStyle, ...)
    u8 m_field_0AF;  // 0x0AF [R] (DoStream)
    u32 m_field_0B0;  // 0x0B0 [R/W] (ClearSim, DoStream, SwitchMidLayerSleeveToFirstAvailableStyle, ...)
    u8 m_field_0B3;  // 0x0B3 [R] (DoStream)
    u8 m_bodyPartIndex_0B4;  // 0x0B4 [R/W] (ClearSim, GetBodyPartIndex, InnerLayerHalfTorsoRequired, ...)
    u8 m_bodyPartTextureIndex_0B5;  // 0x0B5 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex, ...)
    u8 _pad_0B6[2];  // 0x0B6
    u32 m_field_0B8;  // 0x0B8 [R/W] (ClearSim, DoStream, SwitchOuterLayerTorsoToFirstAvailableStyle, ...)
    u8 m_field_0BB;  // 0x0BB [R] (DoStream)
    u32 m_field_0BC;  // 0x0BC [R/W] (ClearSim, DoStream, SwitchOuterLayerCollarToFirstAvailableStyle, ...)
    u8 m_field_0BF;  // 0x0BF [R] (DoStream)
    u32 m_field_0C0;  // 0x0C0 [R/W] (ClearSim, DoStream, SwitchOuterLayerSleeveToFirstAvailableStyle, ...)
    u8 m_field_0C3;  // 0x0C3 [R] (DoStream)
    u8 m_bodyPartIndex_0C4;  // 0x0C4 [R/W] (ClearSim, GetBodyPartIndex, InitializeToDefaultCostume, ...)
    u8 m_bodyPartTextureIndex_0C5;  // 0x0C5 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_0C6[2];  // 0x0C6
    u32 m_field_0C8;  // 0x0C8 [R/W] (ClearSim, DoStream, ShouldBootTopBeDisplayed, ...)
    u8 m_field_0CB;  // 0x0CB [R] (DoStream)
    u8 m_bodyPartIndex_0CC;  // 0x0CC [R/W] (ClearSim, GetBodyPartIndex, InitializeToDefaultCostume, ...)
    u8 m_bodyPartTextureIndex_0CD;  // 0x0CD [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_0CE[2];  // 0x0CE
    u32 m_field_0D0;  // 0x0D0 [R/W] (ClearSim, ShouldBootTopBeDisplayed, Verify)
    u8 m_bodyPartIndex_0D4;  // 0x0D4 [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartIndex_0D5;  // 0x0D5 [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex, ...)
    u8 m_bodyPartTextureIndex_0D6;  // 0x0D6 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_0D7[1];  // 0x0D7
    u32 m_field_0D8;  // 0x0D8 [W] (ClearSim, DoStream, SwitchHatToFirstAvailableStyle)
    u8 m_field_0DB;  // 0x0DB [R] (DoStream)
    u8 m_bodyPartIndex_0DC;  // 0x0DC [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex_0DD;  // 0x0DD [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_0DE[2];  // 0x0DE
    u32 m_field_0E0;  // 0x0E0 [W] (ClearSim)
    u32 m_field_0E4;  // 0x0E4 [W] (ClearSim)
    u8 m_bodyPartIndex_0E8;  // 0x0E8 [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex_0E9;  // 0x0E9 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 m_bodyPartIndex_0EA;  // 0x0EA [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex_0EB;  // 0x0EB [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u32 m_field_0EC;  // 0x0EC [W] (ClearSim, DoStream)
    u8 m_field_0EF;  // 0x0EF [R] (DoStream)
    u8 m_bodyPartIndex_0F0;  // 0x0F0 [R/W] (ClearSim, GetBodyPartIndex, SetBodyPartIndex)
    u8 m_bodyPartTextureIndex_0F1;  // 0x0F1 [R/W] (ClearSim, GetBodyPartTextureIndex, SetBodyPartTextureIndex)
    u8 _pad_0F2[6];  // 0x0F2
    f32 m_bodyTypeMorphValues_0F8;  // 0x0F8 [R/W] (CasSimDescriptionS2C, ClearSim, SetBodyTypeMorphValues, ...)
    f32 m_bodyTypeMorphValues_0FC;  // 0x0FC [R/W] (CasSimDescriptionS2C, ClearSim, SetBodyTypeMorphValues, ...)
    f32 m_bodyTypeMorphValues_100;  // 0x100 [R/W] (CasSimDescriptionS2C, ClearSim, SetBodyTypeMorphValues, ...)
    f32 m_field_104;  // 0x104 [R/W] (CasSimDescriptionS2C, ClearSim, Verify)
    f32 m_field_108;  // 0x108 [R/W] (CasSimDescriptionS2C, ClearSim, Verify)
    f32 m_field_10C;  // 0x10C [R/W] (CasSimDescriptionS2C, ClearSim, Verify)
    f32 m_field_110;  // 0x110 [R/W] (CasSimDescriptionS2C, ClearSim, Verify)
    f32 m_field_114;  // 0x114 [R/W] (CasSimDescriptionS2C, ClearSim, Verify)
    u32 m_field_118;  // 0x118 [W] (ClearSim)
    u8 _pad_11C[5];  // 0x11C
    u8 m_field_121;  // 0x121 [R/W] (ClearSim, Verify)
};

#endif // CASSIMDESCRIPTIONS2C_H
