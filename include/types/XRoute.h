/* include/types/XRoute.h — canonical layout for XRoute + RouteGoal
 *
 * S17 TypeArchaeologist Phase 1B deliverable #10.
 *
 * typereq:cXRouting RESOLVED. The actual class is **XRoute** (no `cXRouting`
 * exists in the symbol map; xrouting.obj contains XRoute + RouteGoal + Path
 * + PenaltyRect + TileList + BuildRoomPartition free functions).
 *
 * Provenance: SEMANTIC-style matched files at src/matched/xroute/ and
 * src/matched/agent/match_*XRoute*.cpp (~30 matched files for this class).
 *
 * The 80B `pad[80]` between m_begin/m_end (offsets 0x08..0x53) is intentional
 * opacity — those bytes contain the routing-state working set that no
 * matched accessor has touched yet. ClearCurrentGoal verified the boundary
 * fields at 0x54 (m_currentGoal) and 0x58 (m_score).
 */
#ifndef SIMS2_TYPES_XROUTE_H
#define SIMS2_TYPES_XROUTE_H

#include "../types.h"

/* Forward decls */
struct cXObject;
struct cXPerson;
struct RoutingSlot;
struct ReconBuffer;
struct TileList;
struct FTilePt;
struct RouteGoal;

/* ============================================================================
 * RouteGoal (XRouteGoal) — single route goal entry
 *
 * Layout from ClearCurrentGoal evidence (0x80152FF0): array element stride
 * `<<4` = 16 bytes. Inner field at +0x08 set to 0 to clear. The rest of the
 * 16B slot is opaque.
 * ========================================================================== */
struct RouteGoal {
    /* 0x00 */ u8  _pad00[0x08];
    /* 0x08 */ s32 m_field_8;   /* zeroed by ClearCurrentGoal */
    /* 0x0C */ u8  _pad0C[0x04];
    /* total: 16B */
};

/* ============================================================================
 * XRoute — pathing-route state
 *
 * Verified offsets (every one from semantic-style matched files):
 *   0x00 m_begin           — RouteGoal* (start of goal array)
 *   0x04 m_end             — RouteGoal* (one-past-last)
 *   0x54 m_currentGoal     — s32, index into goals; -1 = none
 *                            (ClearCurrentGoal sets to -1; GetCurrentGoal
 *                            indexes &m_begin[m_currentGoal])
 *   0x58 m_score           — s32, score for current goal; -1 when cleared
 *
 * The 80B (0x50) span 0x08..0x53 is opaque routing-state working area.
 * GetMaxScore and BuildGoalList likely access fields in there; trace those
 * stubs when needed (0x80152F98 GetMaxScore, 0x8015597C BuildGoalList).
 * ========================================================================== */
struct XRoute {
    /* 0x00 */ RouteGoal*  m_begin;
    /* 0x04 */ RouteGoal*  m_end;
    /* 0x08 */ u8          _padInner[0x4C];   /* routing state working area */
    /* 0x54 */ s32         m_currentGoal;     /* -1 = no current goal */
    /* 0x58 */ s32         m_score;           /* -1 when cleared */
    /* 0x5C */ u8          _padTail[0x100];   /* opaque tail */
};

/* ============================================================================
 * Function prototypes — XRoute matched methods
 * ========================================================================== */

/* Construction */
extern "C" void f_80152D18(void); /* XRoute::XRoute(void)                     */
extern "C" void f_80152D74(void); /* XRoute::XRoute(cXObject*, cXObject*, RoutingSlot*) */
extern "C" void f_803AB95C(void); /* XRoute::XRoute(XRoute&) — copy ctor      */
extern "C" void f_80152DDC(void); /* XRoute::Construct(cXObject*, cXObject*, RoutingSlot*) */

/* Goal management */
extern "C" int  f_80152F5C(void); /* XRoute::HasCurrentGoal()                 */
extern "C" int  f_80152F74(void); /* XRoute::CountGoals() — (end-begin)       */
extern "C" void f_80152F88(void); /* XRoute::GetNthGoal(int)                  */
extern "C" void f_80152F98(void); /* XRoute::GetMaxScore()                    */
extern "C" void f_80152FF0(void); /* XRoute::ClearCurrentGoal()               */
extern "C" void f_80153044(void); /* XRoute::AddGoal(RouteGoal&)              */
extern "C" void f_80153248(void); /* XRoute::GetCurrentGoal()                 */
extern "C" void f_801534C8(void); /* XRoute::DoStream(ReconBuffer*, int)      */
extern "C" void f_801534CC(void); /* XRoute::ResetGoals()                     */
extern "C" void f_8015325C(void); /* XRoute::IsPersonSittingOnChairGoal(cXPerson*) */
extern "C" void f_80153328(void); /* XRoute::ShouldIgnore(cXObject*)          */
extern "C" void f_8015597C(void); /* XRoute::BuildGoalList()                  */

/* Evaluation / pathfinding */
extern "C" void f_8015282C(void); /* XRoute::EvalTileForGoal(FTilePt&, int)   */
extern "C" void f_80155AC8(void); /* XRoute::FindPath(TileList&)              */
extern "C" void f_80158058(void); /* XRoute::ChooseStartingPoint()            */
extern "C" void f_80158318(void); /* XRoute::ConstructGoals()                 */

/* Slot access */
extern "C" void f_80152C30(void); /* XRoute::GetRoutingSlot() (approx — confirm) */

#endif /* SIMS2_TYPES_XROUTE_H */
