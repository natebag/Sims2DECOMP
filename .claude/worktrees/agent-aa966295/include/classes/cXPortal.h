#ifndef CXPORTAL_H
#define CXPORTAL_H

#include "types.h"

// cXPortal - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 8 known fields (0 named), 22 methods

class cXPortal {
public:
    // Constructors / Destructors
    cXPortal(int)  // 0x8038EC8C
    ~cXPortal(void);  // 0x8038611C

    // Methods
    void EstimateDistance(ObjectModule *, cXObject *, cXObject *);  // 0x8038CDAC (884B)
    void DirtyAllRoutes(ObjectModule *);  // 0x8038C4D0 (324B)
    void FailedPortalTree(ObjectModule *, cXObject *, cXPortal *);  // 0x8038DB8C (280B)
    void InitPortalRoute(ObjectModule *, cXObject *, cXObject *);  // 0x8038C614 (272B)
    void FindBestPortal(ObjectModule *, cXObject *, cXObject *);  // 0x8038D380 (2060B)
    void BeginningPortalTree(ObjectModule *, cXObject *, cXPortal *);  // 0x8038DCA4 (1076B)
    void setPortalImpl(cXPortalImpl *);  // 0x8038EFDC (64B)
    void CAST_IMPL(void);  // 0x8038F01C (120B)
    void DumpRouteScores(ObjectModule *, short);  // 0x8038E0D8 (780B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (BeginningPortalTree, DirtyAllRoutes, DumpRouteScores, ...)
    u32 m_field_004;  // 0x004 [R/W] (BeginningPortalTree, DumpRouteScores, EstimateDistance, ...)
    u32 m_field_008;  // 0x008 [R] (BeginningPortalTree, DirtyAllRoutes, DumpRouteScores, ...)
    u32 m_field_00C;  // 0x00C [R] (BeginningPortalTree, DumpRouteScores, FindBestPortal, ...)
    u32 m_field_010;  // 0x010 [R] (cXPortal, ~cXPortal)
    u32 m_field_014;  // 0x014 [R] (cXPortal, ~cXPortal)
    u8 _pad_018[0xC];  // 0x018
    u32 m_field_024;  // 0x024 [W] (cXPortal)
    u8 _pad_028[4];  // 0x028
    u32 m_field_02C;  // 0x02C [R/W] (cXPortal)
};

#endif // CXPORTAL_H
