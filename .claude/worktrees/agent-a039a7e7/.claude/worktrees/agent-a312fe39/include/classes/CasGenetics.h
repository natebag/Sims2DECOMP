#ifndef CASGENETICS_H
#define CASGENETICS_H

#include "types.h"

// CasGenetics - struct layout extracted from assembly analysis
// Estimated minimum size: 0x88 (136 bytes)
// 7 known fields (1 named), 39 methods

class CasGenetics {
public:
    // Constructors / Destructors
    CasGenetics(void)  // 0x8042F6CC
    ~CasGenetics(void);  // 0x8042F75C

    // Methods
    void ClearGrandparentsList(void);  // 0x804306AC (256B)
    void BlendSimDescriptions(CasSimDescriptionS2C &, CasSimDescriptionS2C &, CasSimDescriptionS2C &, bool);  // 0x8042F804 (648B)
    void BlendSkinColor(signed char, signed char);  // 0x8042FA8C (428B)
    void ChooseRandomBodyPart(eBodyPartS2C, CasSimDescriptionS2C &, int);  // 0x8042FF34 (1912B)
    void BlendBodyType(signed char, signed char);  // 0x8042FC38 (468B)
    void BlendMorphValues(float, float);  // 0x8042FE0C (112B)
    void ChoosePersonalityTraits(CasSimDescriptionS2C &);  // 0x8042FE7C (184B)
    void FemaleInnerLayerTorsoLocked(signed char);  // 0x804316D4 (96B)
    void FemaleFacialFeatureLocked(signed char);  // 0x80431734 (192B)
    void LoadGrandparentList(bool);  // 0x804307AC (364B)
    void CreateNewGrandparentList(void);  // 0x80430FF0 (424B)
    void SaveGrandparentList(void);  // 0x80430918 (632B)
    void DoStream(ReconBuffer *, int);  // 0x80430B90 (1120B)
    void LoadGrandparentPortraits(void);  // 0x80431198 (440B)
    /* ? */ GetGrandparentPortraitName(bool, unsigned int);  // 0x80431554 (176B)
    /* ? */ GetGrandparent(bool, unsigned int);  // 0x80431350 (176B)
    void UpdateGrandparentDescription(bool, unsigned int, CasSimDescriptionS2C &);  // 0x80431400 (340B)
    /* ? */ GetNumGrandparents(bool);  // 0x804DF904 (88B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoStream, Grandparent::~Grandparent, LoadGrandparentList, ...)
    u32 m_field_004;  // 0x004 [R/W] (ClearGrandparentsList, DoStream, Grandparent::~Grandparent, ...)
    u32 m_field_008;  // 0x008 [R/W] (LoadGrandparentList)
    u32 m_field_00C;  // 0x00C [R/W] (DoStream)
    u32 m_field_010;  // 0x010 [R] (DoStream, LoadGrandparentPortraits)
    u32 m_field_014;  // 0x014 [R] (LoadGrandparentPortraits)
    u8 _pad_018[0x6C];  // 0x018
    u32 m_field_084;  // 0x084 [W] (CreateNewGrandparentList)
};

#endif // CASGENETICS_H
