#ifndef XROUTE_H
#define XROUTE_H

#include "types.h"

// XRoute - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4A8 (1192 bytes)
// 47 known fields (4 named), 74 methods

class XRoute {
public:
    // Constructors / Destructors
    XRoute(XRoute &)  // 0x80378898
    XRoute(cXObject *, cXObject *, RoutingSlot *)  // 0x803E9ED4
    XRoute(void)  // 0x803E9E40
    ~XRoute(void);  // 0x80378848

    // Methods
    /* ? */ GetDest(void);  // 0x80378B20 (44B)
    /* ? */ GetStart(void);  // 0x80378B4C (44B)
    /* ? */ GetValid(void);  // 0x80378D30 (44B)
    void SetCurPortal(cXPortal *);  // 0x80378CAC (40B)
    void SetValid(bool);  // 0x80378D5C (40B)
    /* ? */ GetTrapCount(void);  // 0x80378B78 (44B)
    /* ? */ GetLastLocation(void);  // 0x80378C20 (44B)
    void SetResult(int);  // 0x80378EB4 (40B)
    /* ? */ GetResult(void);  // 0x80378E88 (44B)
    /* ? */ GetMovingPerson(void);  // 0x80378DAC (44B)
    /* ? */ GetMovingInteractionID(void);  // 0x80378DD8 (44B)
    void SetMoveSuccess(bool);  // 0x80378E60 (40B)
    void SetMovingPerson(cXPerson *, int);  // 0x80378E04 (48B)
    /* ? */ GetBlockingObjectID(void);  // 0x80378EDC (48B)
    /* ? */ GetCurPortal(void);  // 0x80378C80 (44B)
    /* ? */ GetFootprintMask(void);  // 0x80378CD4 (48B)
    /* ? */ GetExitDirFlag(void);  // 0x80378D04 (44B)
    /* ? */ GetWaitStartTicks(void);  // 0x80378BCC (44B)
    /* ? */ GetMoveSuccess(void);  // 0x80378E34 (44B)
    void SetWaitStartTicks(int);  // 0x80378BF8 (40B)
    void SetTrapCount(int);  // 0x80378BA4 (40B)
    void SetLastLocation(FTilePt &);  // 0x80378C4C (52B)
    void SetPersonToIgnore(cXPerson *);  // 0x80378D84 (40B)
    void SetIgnoreAllPeople(bool);  // 0x80378F0C (40B)
    void operator=(XRoute &);  // 0x803789A4 (380B)
    /* ? */ GetRoutingSlot(void);  // 0x803EA50C (44B)
    void BuildGoalList(void);  // 0x803EBC94 (512B)
    bool IsPersonSittingOnChairGoal(cXPerson *);  // 0x803EA670 (380B)
    void ShouldIgnore(cXObject *);  // 0x803EA7EC (808B)
    void FindPath(TileList &);  // 0x803EBE94 (6448B)
    bool HasCurrentGoal(void);  // 0x803EA1A0 (64B)
    /* ? */ GetCurrentGoal(void);  // 0x803EA598 (216B)
    void ResetGoals(void);  // 0x803EAB3C (72B)
    void DoStream(ReconBuffer *, int);  // 0x803EAB14 (40B)
    void EvalTileForGoal(FTilePt &, int);  // 0x803E9650 (1284B)
    void Construct(cXObject *, cXObject *, RoutingSlot *);  // 0x803E9F80 (544B)
    void CountGoals(void);  // 0x803EA1E0 (68B)
    /* ? */ GetNthGoal(int);  // 0x803EA224 (76B)
    /* ? */ GetMaxScore(void);  // 0x803EA270 (176B)
    void SetCurrentGoal(int);  // 0x803EA320 (204B)
    void ClearCurrentGoal(void);  // 0x803EA3EC (288B)
    void AddGoal(RouteGoal &);  // 0x803EA538 (96B)
    /* ? */ GetPersonVisibilityRadius(void);  // 0x803F191C (40B)
    void ChooseStartingPoint(void);  // 0x803EDD78 (952B)
    void ConstructGoals(void);  // 0x803EE130 (6120B)
    void SetStartPt(FTilePt &);  // 0x803F18C0 (52B)
    void SetExitDirFlag(int);  // 0x803F18F4 (40B)
    /* ? */ GetStartPt(void);  // 0x803F1894 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddGoal, BuildGoalList, ClearCurrentGoal, ...)
    u32 m_maxScore_004;  // 0x004 [R/W] (AddGoal, BuildGoalList, ClearCurrentGoal, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddGoal, ConstructGoals, FindPath, ...)
    s16 m_field_00C;  // 0x00C [R/W] (AddGoal, ConstructGoals, FindPath, ...)
    u8 _pad_00E[2];  // 0x00E
    u32 m_field_010;  // 0x010 [R/W] (Construct, ConstructGoals, FindPath, ...)
    u32 m_field_014;  // 0x014 [W] (ConstructGoals)
    s16 m_field_018;  // 0x018 [R/W] (ConstructGoals, FindPath)
    u8 _pad_01A[2];  // 0x01A
    u32 m_field_01C;  // 0x01C [R] (EvalTileForGoal, FindPath)
    u8 _pad_020[0x14];  // 0x020
    u32 m_field_034;  // 0x034 [R] (FindPath)
    u8 _pad_038[0x14];  // 0x038
    u32 m_bIsPersonSittingOnChairGoal;  // 0x04C [R/W] (ChooseStartingPoint, Construct, ConstructGoals, ...)
    u32 m_field_050;  // 0x050 [R/W] (BuildGoalList, ChooseStartingPoint, Construct, ...)
    u32 m_field_054;  // 0x054 [R/W] (ClearCurrentGoal, Construct, XRoute)
    u32 m_maxScore_058;  // 0x058 [R/W] (AddGoal, ClearCurrentGoal, Construct, ...)
    u32 m_field_05C;  // 0x05C [W] (Construct, XRoute)
    u32 m_field_060;  // 0x060 [W] (Construct, XRoute)
    u32 m_field_064;  // 0x064 [W] (XRoute)
    u32 m_field_068;  // 0x068 [W] (XRoute)
    u32 m_field_06C;  // 0x06C [W] (Construct, XRoute)
    u32 m_field_070;  // 0x070 [R/W] (ChooseStartingPoint, ConstructGoals, FindPath, ...)
    u32 m_field_074;  // 0x074 [R/W] (ChooseStartingPoint, ConstructGoals, FindPath, ...)
    u32 m_field_078;  // 0x078 [W] (ChooseStartingPoint, XRoute)
    u32 m_field_07C;  // 0x07C [W] (Construct, XRoute)
    u32 m_field_080;  // 0x080 [R/W] (Construct, EvalTileForGoal, ShouldIgnore, ...)
    s16 m_field_084;  // 0x084 [R/W] (ChooseStartingPoint, Construct, ConstructGoals, ...)
    u8 _pad_086[2];  // 0x086
    u32 m_field_088;  // 0x088 [W] (Construct, XRoute)
    u32 m_field_08C;  // 0x08C [R/W] (Construct, ConstructGoals, FindPath, ...)
    u16 m_field_090;  // 0x090 [W] (Construct, ConstructGoals, EvalTileForGoal, ...)
    u8 _pad_092[2];  // 0x092
    u32 m_field_094;  // 0x094 [R/W] (Construct, ShouldIgnore, XRoute)
    s16 m_field_098;  // 0x098 [R/W] (FindPath, XRoute)
    u8 _pad_09A[2];  // 0x09A
    s16 m_field_09C;  // 0x09C [R/W] (BuildGoalList, Construct, FindPath, ...)
    u8 _pad_09E[2];  // 0x09E
    u32 m_field_0A0;  // 0x0A0 [R/W] (BuildGoalList, Construct, ConstructGoals, ...)
    u8 _pad_0A4[0x174];  // 0x0A4
    s16 m_field_218;  // 0x218 [R] (FindPath)
    u8 _pad_21A[2];  // 0x21A
    u32 m_field_21C;  // 0x21C [R] (FindPath)
    u8 _pad_220[0x38];  // 0x220
    s16 m_field_258;  // 0x258 [R] (FindPath)
    u8 _pad_25A[2];  // 0x25A
    u32 m_field_25C;  // 0x25C [R] (FindPath)
    s16 m_field_260;  // 0x260 [R] (FindPath)
    u8 _pad_262[2];  // 0x262
    u32 m_field_264;  // 0x264 [R] (FindPath)
    u8 _pad_268[0xA0];  // 0x268
    s16 m_field_308;  // 0x308 [R] (FindPath)
    u8 _pad_30A[2];  // 0x30A
    u32 m_field_30C;  // 0x30C [R] (FindPath)
    u8 _pad_310[8];  // 0x310
    s16 m_field_318;  // 0x318 [R] (FindPath)
    u8 _pad_31A[2];  // 0x31A
    u32 m_field_31C;  // 0x31C [R] (FindPath)
    s16 m_field_320;  // 0x320 [R] (FindPath)
    u8 _pad_322[2];  // 0x322
    u32 m_field_324;  // 0x324 [R] (FindPath)
    u8 _pad_328[0x168];  // 0x328
    s16 m_field_490;  // 0x490 [R] (FindPath)
    u8 _pad_492[2];  // 0x492
    u32 m_field_494;  // 0x494 [R] (FindPath)
    u8 _pad_498[8];  // 0x498
    s16 m_field_4A0;  // 0x4A0 [R] (FindPath)
    u8 _pad_4A2[2];  // 0x4A2
    u32 m_field_4A4;  // 0x4A4 [R] (FindPath)
};

#endif // XROUTE_H
