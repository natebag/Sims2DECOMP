#ifndef CASSIMPARTSS2C_H
#define CASSIMPARTSS2C_H

#include "types.h"

// CasSimPartsS2C - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (3 named), 73 methods

class CasSimPartsS2C {
public:
    // Constructors / Destructors
    CasSimPartsS2C(void)  // 0x8045362C
    ~CasSimPartsS2C(void);  // 0x80453714

    // Methods
    void SetInGame(bool);  // 0x80161934 (40B)
    /* ? */ GetInGame(void);  // 0x8016195C (44B)
    /* ? */ GetSimParts(void);  // 0x80161988 (44B)
    void SetGender(bool);  // 0x80453788 (312B)
    /* ? */ GetModelID(eBodyPartS2C, unsigned int, Sim::SimPartsS2CParam);  // 0x80453FE4 (5260B)
    /* ? */ GetBodyPartName(eBodyPartS2C);  // 0x8045AB38 (344B)
    /* ? */ GetWeldableBodyPartConnections(eBodyPartS2C, unsigned int *, unsigned int);  // 0x80459AF4 (3740B)
    void OuterLayerTorsoIsAHood(unsigned int, Sim::OuterLayerTorsoStyleS2C);  // 0x80458954 (316B)
    void OuterLayerCollarIsAHood(unsigned int, Sim::OuterLayerCollarStyleS2C);  // 0x8045878C (456B)
    /* ? */ GetSkinTexturesDatasetID(eSkinColorType, eBodyTypeS2C);  // 0x804556A8 (488B)
    /* ? */ GetIndexFromResId(eBodyPartS2C, int, Sim::SimPartsS2CParam, int *);  // 0x80459940 (252B)
    void LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, unsigned int);  // 0x8045864C (320B)
    void MidLayerTorsoHidesBelt(unsigned int, Sim::MidLayerTorsoStyleS2C, unsigned int);  // 0x80458C7C (416B)
    void OuterLayerTorsoHidesBelt(unsigned int, Sim::OuterLayerTorsoStyleS2C, unsigned int);  // 0x80458E1C (424B)
    void OuterLayerTorsoHidesMusicPlayer(unsigned int);  // 0x804585D8 (116B)
    /* ? */ GetTextureID(eBodyPartS2C, CasSimDescriptionS2C *, bool);  // 0x804559D8 (8544B)
    /* ? */ GetTattooTextureID(eTattooTextureTypeS2C, unsigned int);  // 0x80457B98 (404B)
    /* ? */ GetSkinTextureID(eSkinColorType, eBodyTypeS2C, eSimPartsMapLocation);  // 0x80455470 (568B)
    /* ? */ GetReflectionTextureID(eBodyPartS2C, CasSimDescriptionS2C *);  // 0x80457B38 (96B)
    /* ? */ GetUnlockGroupNum(eBodyPartS2C, unsigned int);  // 0x80458FC4 (1144B)
    /* ? */ GetUnlockGroupNum(eTattooTextureTypeS2C, unsigned int);  // 0x8045943C (716B)
    /* ? */ GetNumBodyModels(eBodyPartS2C);  // 0x804538C0 (624B)
    /* ? */ GetNumBodyTextures(eBodyPartS2C, unsigned int);  // 0x80453B30 (1052B)
    /* ? */ GetNumBodyPartOptions(eBodyPartS2C);  // 0x8045A990 (424B)
    void OuterLayerTorsoRequiresFullTorsoMeshInMidLayer(unsigned int);  // 0x80458564 (116B)
    /* ? */ GetNumTattooTextures(eTattooTextureTypeS2C);  // 0x80453F4C (152B)
    /* ? */ GetTattoosForLocation(eTattooTextureTypeS2C, unsigned char *);  // 0x80459708 (344B)
    /* ? */ GetGameStateModelID(unsigned int);  // 0x80459A3C (92B)
    /* ? */ GetGameStateTextureID(unsigned int);  // 0x80459A98 (92B)
    /* ? */ GetTextureIDFromVector(VECTOR<unsigned int> &, int, bool, unsigned char, char *);  // 0x80455890 (328B)
    bool IsGamecubeOnly(eBodyPartS2C, unsigned int);  // 0x80457D2C (936B)
    /* ? */ GetIconTextureId(eBodyPartS2C, unsigned int);  // 0x804580D4 (776B)
    /* ? */ GetIconTattooTextureId(eTattooTextureTypeS2C, unsigned int);  // 0x804583DC (392B)
    bool CanBeWornSleeveless(eBodyPartS2C, unsigned int, Sim::SimPartsS2CParam);  // 0x80458A90 (492B)
    void ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C);  // 0x80459860 (224B)
    void VerifyBodyPartsData(void);  // 0x8045AC90 (13112B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CasSimPartsS2C, SetGender, ~CasSimPartsS2C)
    u32 m_numTattooTextures;  // 0x004 [R/W] (CanBeWornSleeveless, CasSimPartsS2C, GetIconTattooTextureId, ...)
    u32 m_skinTexturesDatasetID;  // 0x008 [R/W] (CasSimPartsS2C, GetModelID, GetSkinTextureID, ...)
    u32 m_field_00C;  // 0x00C [W] (CasSimPartsS2C)
};

#endif // CASSIMPARTSS2C_H
