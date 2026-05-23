/* include/types/ERoom.h — canonical class layout for ERoom (eroom.obj)
 *
 * S17 TypeArchaeologist Phase 1 deliverable #4.
 *
 * Provenance: ASMPROC inject_before stubs in src/matched/agent/.
 *
 * Note on the typereq name: SonnetWorker2 (Lane 6) asked for `cXRoom`. The
 * actual class is `ERoom` (per `extracted/files/u2_ngc_release.map`). There
 * is no class named cXRoom. eroom.obj contains:
 *   - ERoom (this header)
 *   - ERoomWall (a separate header, written when typereq:ERoomWall lands)
 *
 * Recovered layout summary:
 *   Nine TNodeList<ERoomWall*>-like inline lists (12 bytes each) live at
 *   offsets 0x04..0x6F, with parallel pointers at 0x70..0x90 indexing them
 *   by "wall id". This pattern (intrusive list head + count + sentinel-bool)
 *   is consistent across all 9 instances and the SetWallState loop
 *   (0x8002E8A4) iterates 8 of them with uniform vcalls.
 *
 *   An ERedBlackTree<RoomID, RoomData> lives at +0xA0 (m_tree). RoomData has
 *   inline fields for WallsOpaque (+0x10 by wallId stride 4), OccludeAlpha
 *   (+0x18, float by wallId stride 4), RoofOpaque (+0x24 by wallId stride 4),
 *   and a wall-list head pointer at +0x1C (used by GetNumWalls).
 */
#ifndef SIMS2_TYPES_EROOM_H
#define SIMS2_TYPES_EROOM_H

#include "../types.h"

/* Forward decls */
struct ERoomWall;
struct CTilePt;
struct TileWalls;
struct ERedBlackTreeNode;

/* ============================================================================
 * Inline TNodeList<ERoomWall*> — the per-wall-id list node
 *
 * Evidence (ERoom::ERoom ctor 0x8002D778):
 *   addi r20,r30,4         ; r20 = this+0x4 (list0 base)
 *   li   r29, 0
 *   li   r0,  1
 *   stw  r29, 0x4(r30)     ; list0->head = NULL
 *   stw  r29, 0x4(r20)     ; list0->count = 0    (this+0x8)
 *   stw  r0,  0x8(r20)     ; list0->flag = 1     (this+0xC)
 *   ... same for lists 1..8 at strides of +0x0C
 * ========================================================================== */
struct ERoom_WallList {
    /* 0x00 */ ERoomWall* m_head;  /* zeroed in ctor */
    /* 0x04 */ s32        m_count; /* zeroed in ctor */
    /* 0x08 */ s32        m_flag;  /* set to 1 in ctor (likely sentinel/init marker) */
};

/* ============================================================================
 * ERoom — per-room scene/wall manager
 *
 * Embedded layout. 9 inline ERoom_WallList structures occupy the front of the
 * object, followed by a parallel 9-pointer index array.
 * ========================================================================== */
struct ERoom {
    /* 0x000 */ void*            m_field00; /* zeroed in ctor (stw 29,0x0(30)).
                                                Possible vtable slot — no vtable
                                                store observed in this ctor, so
                                                either non-virtual or set by a
                                                derived ctor / vtable copy
                                                further upstream. */
    /* 0x004 */ ERoom_WallList   m_wallLists[9]; /* 9 × 12 = 108B, spans 0x004..0x06F.
                                                    Each accessed by wall id 0..8. */
    /* 0x070 */ ERoom_WallList*  m_wallListPtrs[9]; /* 9 × 4 = 36B; each points at
                                                       &m_wallLists[i]. Pattern in
                                                       ctor:
                                                       stw r20,0x70(r30) ; ... */
    /* 0x094 */ u8               m_field94[0x0C]; /* small sub-object constructed
                                                     by _s8002D778_0; size 12B
                                                     unverified — possibly a
                                                     TArrayDefault<>::Init() head */
    /* 0x0A0 */ u8               m_tree[0x0C];    /* ERedBlackTree<RoomID,RoomData>
                                                     constructed by _s8002D778_1.
                                                     Size 12B confirmed: next field
                                                     starts at 0xAC. */
    /* 0x0AC */ float            m_wallFadeStart; /* init from rodata 0x80008E30 */
    /* 0x0B0 */ float            m_wallFadeEnd;   /* init from rodata 0x80008E34 */
    /* 0x0B4 */ u8               _padTail[0x100]; /* opaque extent — class total
                                                     size unverified, more fields
                                                     accessed by methods that
                                                     read past 0xB4 */
};

/* ============================================================================
 * Per-RoomData (the value-type stored in ERoom::m_tree)
 *
 * Returned by ERedBlackTree::Find via a sequence:
 *   addi r3,r3,160     ; r3 = &this->m_tree
 *   li   r5, 0
 *   bl   <Find>        ; returns pointer to RoomData node
 *   ...
 *   lwz  r3,0x1C(r3)   ; data->m_wallListHead   (used by GetNumWalls)
 *   addi r9,r3,16      ; &data->m_wallsOpaque[0]   (GetWallsOpaque, GetRoofOpaque)
 *   addi r9,r3,8       ; &data->m_occludeAlpha[0]  (GetOccludeAlpha — float[])
 *   addi r9,r3,24      ; &data->m_roofOpaque[0]    (IsRoomRoofOpaque)
 *
 * The 4-byte stride per wall id (rlwinm 0,r31,2,0,29) is shared across all
 * accessors, so these are arrays indexed by wall id. Treat the struct as
 * opaque and access via the matched ERoom getters; the field offsets here
 * are for documentation, not for direct slicing.
 * ========================================================================== */
struct ERoom_RoomData {
    /* opaque envelope — known internal offsets:
     *   +0x08  float[] m_occludeAlpha    (GetOccludeAlpha)
     *   +0x10  s32[]   m_wallsOpaque     (IsRoomWallsOpaque)
     *   +0x1C  void*   m_wallListHead    (GetNumWalls)
     *   +0x24  s32[]   m_roofOpaque      (IsRoomRoofOpaque)
     * Layout interleaves arrays at wall-id stride 4; size depends on the
     * configured wall-id range, so we keep this as a raw byte buffer.
     */
    /* 0x00 */ u8 _opaque[0x40];
};

/* ============================================================================
 * Function prototypes — matched ERoom methods
 * ========================================================================== */

/* Construction / lifecycle */
extern "C" void f_8002D778(void); /* ERoom::ERoom(void)                       */
extern "C" void f_8002D88C(void); /* ERoom::~ERoom(void)                      */
extern "C" void f_8002DCF0(void); /* ERoom::InitRoomLookupTab(void)           */
extern "C" void f_8002EBB8(void); /* ERoom::Init(void)                        */

/* Per-wall-id queries (RoomData accessors via m_tree.Find) */
extern "C" void f_8002DF7C(void); /* ERoom::GetNumWalls(unsigned short)       */
extern "C" void f_8002DFEC(void); /* ERoom::GetWallPaperCost(unsigned int, ...) */
extern "C" void f_8002E168(void); /* ERoom::IsRoomWallsOpaque(int, int)       */
extern "C" void f_8002E268(void); /* ERoom::GetShortDistToCam(int, int)       */
extern "C" void f_8002E2C4(void); /* ERoom::GetOccludeAlpha(int, int)         */
extern "C" void f_8002E324(void); /* ERoom::IsRoomRoofOpaque(int, int)        */
extern "C" void f_8002E380(void); /* ERoom::CalRoofOpaque(int)                */
extern "C" void f_8002E1C4(void); /* ERoom::CalAllRoomOpaque(int)             */
extern "C" void f_8002E74C(void); /* ERoom::CalShortDistToCam(int)            */
extern "C" void f_8002E0C4(void); /* ERoom::DrawWallpaperPreview(ERC*,...)    */

/* Wall list management */
extern "C" void f_8002E8A4(void); /* ERoom::SetWallState(EWallUpDownStateType) */
extern "C" void f_8002EAB8(void); /* ERoom::UpdateWallFade(int)                */
extern "C" void f_8002EC60(void); /* ERoom::ProcStandardWalls(bool,...)        */
extern "C" void f_8002EF04(void); /* ERoom::ProcDiagonalWalls(int&, int&, bool)*/
extern "C" void f_8002F264(void); /* ERoom::ProcessCell(...)                   */
extern "C" void f_80047508(void); /* ERoom::ProcessCell(...) — different overload? */
extern "C" void f_8002F4DC(void); /* ERoom::PreviewWallBuild(bool)             */
extern "C" void f_8002FD08(void); /* ERoom::FindWallContainingSegment(...)     */
extern "C" void f_8002FE18(void); /* ERoom::GetWallFromTileAndSegment(...)     */
extern "C" void f_8002FEAC(void); /* ERoom::DeleteERoomWallContainingSegment(...) */
extern "C" void f_8002FF8C(void); /* ERoom::DeleteWallAtTile(CTilePt&, ...)    */
extern "C" void f_80030104(void); /* ERoom::KillArchitecturalObject(CTilePt&, ...) */

#endif /* SIMS2_TYPES_EROOM_H */
