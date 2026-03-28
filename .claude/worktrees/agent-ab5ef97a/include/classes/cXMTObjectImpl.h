#ifndef CXMTOBJECTIMPL_H
#define CXMTOBJECTIMPL_H

#include "types.h"

// cXMTObjectImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 20 known fields (10 named), 70 methods

class cXMTObjectImpl {
public:
    // Constructors / Destructors
    cXMTObjectImpl(int, ObjSelector *, cXMTObject *, ObjectModule *)  // 0x802605E8
    ~cXMTObjectImpl(void);  // 0x8026280C

    // Methods
    void SetLeader(cXMTObject *);  // 0x80264A70 (148B)
    void RemoveFromChain(void);  // 0x80264F64 (384B)
    void Initialize(void);  // 0x80264990 (224B)
    /* ? */ GetISimInstance(void);  // 0x80264B04 (1120B)
    /* ? */ GetISimInstanceBaseVer(void);  // 0x80269400 (72B)
    void Turn(int);  // 0x802650E4 (968B)
    void AssignOffsets(void);  // 0x802654AC (596B)
    bool CanPlace(FTilePt &, int, cXObject *, int);  // 0x80265700 (588B)
    void Place(FTilePt &, int, cXObject *, int);  // 0x8026594C (752B)
    void Pickup(void);  // 0x80265C3C (368B)
    void UserCanPlace(FTilePt &, int, cXObject *, int);  // 0x80265DAC (572B)
    void UserPlace(FTilePt &, int, cXObject *, int);  // 0x80265FE8 (740B)
    void UserCanPickup(void);  // 0x802662CC (244B)
    void UserPickup(bool);  // 0x802663C0 (728B)
    void UserCanDelete(void);  // 0x80266698 (244B)
    bool IsPartOfMe(cXObject *);  // 0x8026678C (176B)
    void Reset(bool);  // 0x8026683C (544B)
    void ReconType(void);  // 0x80266A5C (52B)
    void ReconStream(ReconBuffer *, int, bool);  // 0x80266A90 (724B)
    void PostLoad(int, bool);  // 0x80266D64 (260B)
    void SetMultiObjectData(int, int);  // 0x80266E68 (340B)
    void MergeDynamic(cXMTObject *);  // 0x80267060 (1088B)
    bool IsDynamic(void);  // 0x802674A0 (148B)
    void RemoveFromDynamic(void);  // 0x80267534 (496B)
    void UpdateAllAdjacecy(void);  // 0x80267724 (312B)
    void UpdateDynAdjacency(void);  // 0x8026785C (612B)
    void MergeInPlace(void);  // 0x80267AC0 (596B)
    /* ? */ GetAverageLocation(void);  // 0x80267D14 (412B)
    /* ? */ GetNumTiles(int &, int &);  // 0x80267EB0 (408B)
    /* ? */ GetFirstMultiTileObject(void);  // 0x80269324 (112B)
    /* ? */ GetNextMultiTileObject(void);  // 0x80269394 (68B)
    /* ? */ GetMTObjectImplementation(void);  // 0x802693D8 (40B)
    void CAST_IMPL(void);  // 0x80269448 (128B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_bIsDynamic;  // 0x000 [R/W] (AssignOffsets, CanPlace, GetAverageLocation, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_averageLocation;  // 0x004 [R/W] (CAST_IMPL, GetAverageLocation, GetISimInstance, ...)
    u32 m_multiObjectData;  // 0x008 [R/W] (AssignOffsets, CanPlace, MergeDynamic, ...)
    u32 m_multiObjectData_00C;  // 0x00C [R/W] (AssignOffsets, CanPlace, MergeDynamic, ...)
    s16 m_iSimInstance;  // 0x010 [R/W] (AssignOffsets, GetISimInstance, RemoveFromChain, ...)
    u8 _pad_012[2];  // 0x012
    u32 m_field_014;  // 0x014 [R/W] (AssignOffsets, RemoveFromChain, cXMTObjectImpl)
    s16 m_numTiles;  // 0x016 [R] (GetNumTiles)
    s16 m_field_018;  // 0x018 [R/W] (AssignOffsets, Initialize, RemoveFromChain, ...)
    u8 _pad_01A[2];  // 0x01A
    u32 m_iSimInstance_01C;  // 0x01C [R/W] (AssignOffsets, CanPlace, GetISimInstance, ...)
    u32 m_bCanPlace;  // 0x020 [R/W] (AssignOffsets, CanPlace, MergeDynamic, ...)
    u32 m_bCanPlace_024;  // 0x024 [R/W] (AssignOffsets, CanPlace, Place, ...)
    u8 _pad_028[0x1C];  // 0x028
    u32 m_field_044;  // 0x044 [W] (cXMTObjectImpl)
    u8 _pad_048[4];  // 0x048
    u32 m_field_04C;  // 0x04C [W] (cXMTObjectImpl)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [W] (cXMTObjectImpl)
    s16 m_field_058;  // 0x058 [R] (RemoveFromChain)
    u8 _pad_05A[2];  // 0x05A
    u32 m_field_05C;  // 0x05C [R] (RemoveFromChain)
    u8 _pad_060[0x10];  // 0x060
    s16 m_field_070;  // 0x070 [R] (Initialize)
    u8 _pad_072[0x26];  // 0x072
    u32 m_field_098;  // 0x098 [R/W] (cXMTObjectImpl)
    u32 m_field_09C;  // 0x09C [R/W] (cXMTObjectImpl)
    u8 _pad_0A0[0x20];  // 0x0A0
    u32 m_iSimInstance_0C0;  // 0x0C0 [R] (GetISimInstance)
};

#endif // CXMTOBJECTIMPL_H
