#ifndef CXPORTALIMPL_H
#define CXPORTALIMPL_H

#include "types.h"

// cXPortalImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x188 (392 bytes)
// 19 known fields (9 named), 40 methods

class cXPortalImpl {
public:
    // Constructors / Destructors
    cXPortalImpl(int, ObjSelector *, cXMTObject *, ObjectModule *)  // 0x80388994
    ~cXPortalImpl(void);  // 0x80386468

    // Methods
    void SetRouteScore(short, float);  // 0x80388868 (300B)
    void Initialize(void);  // 0x8038AE4C (56B)
    void Place(FTilePt &, int, cXObject *, int);  // 0x8038AE84 (116B)
    void ApplyWallStyle(bool);  // 0x8038AEF8 (1048B)
    bool CanPlace(FTilePt &, int, cXObject *, int);  // 0x8038B310 (1404B)
    void Pickup(void);  // 0x8038B88C (964B)
    /* ? */ GetOtherSide(void);  // 0x8038BC50 (872B)
    void ReconType(void);  // 0x8038BFB8 (44B)
    void ReconStream(ReconBuffer *, int, bool);  // 0x8038BFE4 (508B)
    void FindAvailRouteID(ObjectModule *);  // 0x8038C1E0 (752B)
    void ClearRoute(ObjectModule *, short, float);  // 0x8038D120 (264B)
    /* ? */ GetDistToPortal(cXPortal *);  // 0x8038C724 (1672B)
    /* ? */ GetRouteScore(short);  // 0x8038F2C4 (244B)
    void ClearRouteScores(ObjectModule *, short);  // 0x8038D228 (344B)
    /* ? */ GetCustomWallStyleID(void);  // 0x8038E3E4 (136B)
    void PostLoad(int, bool);  // 0x8038E46C (96B)
    /* ? */ GetWallStyle(void);  // 0x8038F3B8 (136B)
    /* ? */ GetPortalImplementation(void);  // 0x8038F440 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ApplyWallStyle, CanPlace, ClearRoute, ...)
    u32 m_distToPortal_004;  // 0x004 [R/W] (ApplyWallStyle, CanPlace, FindAvailRouteID, ...)
    u32 m_distToPortal_008;  // 0x008 [R/W] (ClearRouteScores, GetDistToPortal, GetOtherSide, ...)
    u32 m_distToPortal_00C;  // 0x00C [R/W] (CanPlace, ClearRouteScores, GetDistToPortal, ...)
    u32 m_field_010;  // 0x010 [R] (cXPortalImpl)
    u32 m_field_014;  // 0x014 [R] (cXPortalImpl)
    u8 _pad_018[4];  // 0x018
    u32 m_bCanPlace;  // 0x01C [R] (CanPlace)
    u32 m_bCanPlace_020;  // 0x020 [R] (CanPlace)
    u32 m_bCanPlace_024;  // 0x024 [R] (CanPlace)
    u8 _pad_028[0xC];  // 0x028
    u32 m_field_034;  // 0x034 [W] (cXPortalImpl)
    u8 _pad_038[4];  // 0x038
    u32 m_field_03C;  // 0x03C [W] (cXPortalImpl)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [W] (cXPortalImpl)
    u8 _pad_048[4];  // 0x048
    u32 m_field_04C;  // 0x04C [W] (cXPortalImpl)
    u8 _pad_050[0xC];  // 0x050
    s16 m_wallStyle;  // 0x05C [R] (GetWallStyle)
    u8 _pad_05E[0x32];  // 0x05E
    u32 m_field_090;  // 0x090 [R/W] (cXPortalImpl)
    u32 m_field_094;  // 0x094 [R/W] (cXPortalImpl)
    u8 _pad_098[0xA];  // 0x098
    s16 m_customWallStyleID;  // 0x0A2 [R] (GetCustomWallStyleID)
    u8 _pad_0A4[0xDC];  // 0x0A4
    u32 m_field_180;  // 0x180 [R/W] (cXPortalImpl)
    u32 m_field_184;  // 0x184 [R/W] (cXPortalImpl)
};

#endif // CXPORTALIMPL_H
