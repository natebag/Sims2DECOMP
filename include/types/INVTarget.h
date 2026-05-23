/* include/types/INVTarget.h — partial layout for INVTarget
 *
 * S17 TypeArchaeologist Phase 1B deliverable #11.
 *
 * Service of OpusArchitect's typereq:INVTarget. **Partial coverage** — this
 * header documents the field offsets that are individually verified by
 * matched stubs. The full layout extends much further (writes observed
 * through +0x32E8 in EnterWallBuildMode) but the intermediate fields are
 * not yet evidenced by simple accessors. Treat the tail as opaque.
 *
 * Provenance: ASMPROC stubs in src/matched/agent/match_*INVTarget*.cpp
 * (~30 matched files for this class). OpusArchitect's triangulated 0x84
 * field flagged in his typereq-evidence post and verified here.
 *
 * INVTarget inheritance: descends from some base UI target class (likely
 * BaseTarget / EYETarget per the targets_s2c/targets_tsc3 family) — exact
 * base layout not yet derived. Vtable position unverified.
 */
#ifndef SIMS2_TYPES_INVTARGET_H
#define SIMS2_TYPES_INVTARGET_H

#include "../types.h"

/* Forward decls */
struct ObjSelector;
struct BBI_InventoryItem;
struct ERC;
namespace InteractorModule {
    struct WallData;
    struct WallPaperData;
    struct FloorData;
}

/* ============================================================================
 * INVTarget — Inventory UI target (purchase/shop dispatch hub)
 *
 * Verified offsets (every one from matched-stub asm in src/matched/agent/):
 *
 *   0x000 m_field00            — read in EnterWallBuildMode vcall guard
 *   0x01C m_field1C            — read alongside m_field00 for dispatch
 *   0x07C m_field7C            — sda-relative arg in EnterWallBuildMode
 *   0x084 m_currentTab         — u32 tab index, *4 to index a tab table
 *                                  (GetOnMsgInvCurrentTab 0x801F673C
 *                                   GetOnMsgInvCurrentCell 0x801F677C
 *                                   EnterWallBuildMode 0x801F76A8 reads it)
 *   0x090 m_invHelper          — pointer to inventory helper sub-object
 *                                  (EnterWallBuildMode dispatches through
 *                                   `lwz r3, 0x90(this)`)
 *   0x0BC m_tabCount           — u32, returned by GetOnMsgInvTabCount
 *                                  (0x801F67BC: `lwz r5, 0xbc(r3)`)
 *   0x32E4 m_buildModeActive   — written 1 in EnterWallBuildMode
 *   0x32E8 m_lastBuildResult   — written ret-of-helper in EnterWallBuildMode
 *
 * The 0x32E4/0x32E8 pair confirms the class is huge (≥ 0x32EC bytes total).
 * Most of that span is opaque — only the addresses above have specific
 * accessor evidence.
 *
 * OpusArchitect's hint: the targets_tsc3 family has m_currentFilter,
 * m_shoppingMode flag, m_actionMenu, m_inventoryList, m_categoryList fields
 * somewhere in the opaque span. None individually verified yet — file
 * typereq:INVTarget_<symbol> with the matched-file path when a specific
 * accessor is found, and I'll trace the offset.
 * ========================================================================== */
struct INVTarget {
    /* 0x0000 */ void*     m_field00;          /* used in vcall guard */
    /* 0x0004 */ u8        _pad0004[0x18];
    /* 0x001C */ void*     m_field1C;          /* used in vcall guard alongside m_field00 */
    /* 0x0020 */ u8        _pad0020[0x5C];
    /* 0x007C */ s32       m_field7C;          /* sda-call arg */
    /* 0x0080 */ u8        _pad0080[0x04];
    /* 0x0084 */ u32       m_currentTab;       /* tab index */
    /* 0x0088 */ u8        _pad0088[0x08];
    /* 0x0090 */ void*     m_invHelper;        /* inventory helper sub-object */
    /* 0x0094 */ u8        _pad0094[0x28];
    /* 0x00BC */ u32       m_tabCount;
    /* 0x00C0 */ u8        _padBody[0x3224];   /* opaque body — unverified */
    /* 0x32E4 */ s32       m_buildModeActive;
    /* 0x32E8 */ void*     m_lastBuildResult;
    /* total ≥ 0x32EC; tail unknown */
};

/* ============================================================================
 * Function prototypes — matched INVTarget methods (subset)
 *
 * Full list: src/matched/agent/match_*INVTarget*.cpp + src/matched/invtarget/
 * ========================================================================== */

/* Inventory query getters (read m_currentTab @ 0x84, m_tabCount @ 0xBC) */
extern "C" void f_801F673C(void); /* GetOnMsgInvCurrentTab(char*)             */
extern "C" void f_801F677C(void); /* GetOnMsgInvCurrentCell(char*)            */
extern "C" void f_801F67BC(void); /* GetOnMsgInvTabCount(char*)               */
extern "C" void f_801F67F0(void); /* GetOnMsgInvInventoryCount(char*)         */
extern "C" void f_801F6824(void); /* GetOnMsgInvInventoryReady(char*)         */
extern "C" void f_801F6858(void); /* GetOnMsgInvShpItemCount(char*)           */
extern "C" void f_801F6954(void); /* GetOnMsgInvShpResourcesReady(char*)      */
extern "C" void f_801F6988(void); /* GetOnLocMsgInvShpObjectName(u32, ...)    */
extern "C" void f_801F6A88(void); /* GetOnLocMsgInvShpObjectDescription(u32)  */
extern "C" void f_801F6E88(void); /* GetOnMsgInvShpCanPurchase(char*)         */
extern "C" void f_801F71B8(void); /* GetOnMsgInvShpCanColor(char*)            */
extern "C" void f_801F73BC(void); /* GetOnMsgInvShpColorN(char*)              */
extern "C" void f_801F7470(void); /* GetOnMsgInvShpDefaultColor(char*)        */
extern "C" void f_801F74A4(void); /* GetOnMsgInvShpCategoryCount(char*)       */
extern "C" void f_801F74E8(void); /* GetOnMsgInvShpCategoryN(char*)           */
extern "C" void f_801F7EB0(void); /* GetOnMsgInvShpIsPack(char*)              */
extern "C" void f_801F7F1C(void); /* GetOnMsgInvHelpMode(char*)               */

/* Object info / dispatch */
extern "C" void f_801F5334(void); /* PrepareObjectInfo(WallPaperData)         */
extern "C" void f_801F53EC(void); /* PrepareObjectInfo(FloorData)             */
extern "C" void f_801F54A4(void); /* PrepareObjectInfo(WallData)              */
extern "C" void f_801F5570(void); /* ClearAllObjectInfoData()                 */
extern "C" void f_801F5674(void); /* GetObjectRating(ObjSelector*)            */
extern "C" void f_801F570C(void); /* GetMotiveText(ObjSelector*)              */
extern "C" void f_801F5908(void); /* GetMotiveText(BBI::InventoryItem*)       */
extern "C" void f_801F5A94(void); /* GetMotiveText(int)                       */

/* Mode entry/exit (large bodies — read m_currentTab + write @ 0x32E4/0x32E8) */
extern "C" void f_801F76A8(void); /* EnterWallBuildMode(WallData*)            */
extern "C" void f_801F7924(void); /* EnterWallPaperingMode(WallPaperData*)    */
extern "C" void f_801F7B9C(void); /* EnterFloorTilingMode(FloorData*)         */

/* Cheats / misc */
extern "C" void f_801EFA1C(void); /* Cheat_InstallSelectedCategoryObjectShaders(int) */
extern "C" void f_80336C90(void); /* SetInvBldItemCount()                     */

#endif /* SIMS2_TYPES_INVTARGET_H */
