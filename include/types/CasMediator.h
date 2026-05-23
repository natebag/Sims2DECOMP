/* include/types/CasMediator.h — canonical layout for CasMediator + CasListenerSet
 *
 * S17 TypeArchaeologist Phase 2 deliverable #12.
 *
 * Synthesis of OpusArchitect's `typereq-evidence:CasMediator` (info-board id
 * 3ceee894-3f20-4369-85be-a853a9a2ddf9, Wave 3+5 cleanup commits 55d552961 +
 * 0c2564ae6). 15 cross-referenced matched files under src/matched/casmediator/.
 *
 * **Composition shape:** CasMediator inherits from (or embeds at +0x00) the
 * STL-flavored CasListenerSet (an _Rb_tree-style container). CasMediator-
 * specific fields start at offset 0x10.
 */
#ifndef SIMS2_TYPES_CASMEDIATOR_H
#define SIMS2_TYPES_CASMEDIATOR_H

#include "../types.h"

/* Forward decls */
struct CasSimDescription;       /* edit-sim proxy reached via m_editSim+0x08 */
struct CasSimRenderer;
struct CasSimRendererDynamic;
struct DrawTarget;
struct ERC;

/* ============================================================================
 * CasListenerSet — STL _Rb_tree-shaped listener container
 *
 * Layout per CasMediator::AddListener (0x80161D18) evidence in
 * OpusArchitect's typereq-evidence:CasMediator:
 *   0x00  s32   _M_alloc          (allocator state)
 *   0x04  void* _M_header         (red-black tree root)
 *   0x08  s32   _M_node_count     (listener count; returned by GetListenerCount
 *                                  0x80162028 — 3 cross-refs)
 *   0x0C  char  _M_key_compare    (+ 3B pad)
 * ========================================================================== */
struct CasListenerSet {
    /* 0x00 */ s32   _M_alloc;
    /* 0x04 */ void* _M_header;
    /* 0x08 */ s32   _M_node_count;
    /* 0x0C */ char  _M_key_compare;
    /* 0x0D */ u8    _pad0D[3];
};

/* ============================================================================
 * CasMediator — Create-A-Sim UI/state mediator
 *
 * Inherits CasListenerSet (or embeds at +0x00 — composition vs inheritance
 * not disambiguated; the field layout is identical either way).
 *
 * Field offsets verified across the 15 src/matched/casmediator/ files:
 *
 *   0x08 (from base)  s32  _M_node_count       — GetListenerCount @ 0x80162028
 *   0x10              void* m_editSim           — GetEditSimDescription
 *                                                  (0x801620D8):
 *                                                    lwz r3, 0x10(this)
 *                                                    if (r3) return r3 + 8
 *                                                    else return 0
 *                                                  CasSimDescription proxy is
 *                                                  at m_editSim+0x08.
 *   0x14              void* m_renderer          — polymorphic; used as
 *                                                  CasSimRenderer* /
 *                                                  CasSimRendererDynamic* /
 *                                                  DrawTarget* depending on call
 *                                                  site. Triangulated across 5
 *                                                  files: GetNumBodyModels
 *                                                  (0x801620F4), GetNumTattoo-
 *                                                  Textures (0x80162128),
 *                                                  GetIconTextureId (0x8016215C),
 *                                                  GetIconTattooTextureId
 *                                                  (0x80162190), DrawSim
 *                                                  (0x8016222C).
 *                                                  CAVEAT: could be 1 slot used
 *                                                  3 ways, OR 3 adjacent slots
 *                                                  the matched-file authors
 *                                                  conflated. Treat as opaque
 *                                                  pending ghidra confirmation.
 *   0x20              u32   m_controllerFilters[2] — per-player input filter id
 *                                                  (2-player CAS). Set/Get @
 *                                                  0x801622F4 / 0x8016230C.
 *   0x2C              s32   m_casMode            — current CAS mode; SetCasMode
 *                                                  (0x8016226C) writes here and
 *                                                  mirrors via UIDBSetInt(
 *                                                  g_casModeKey, mode).
 *
 * Tail beyond 0x30 is unverified — treat as opaque.
 * ========================================================================== */
struct CasMediator : public CasListenerSet {
    /* 0x10 */ void*     m_editSim;             /* CasSimDescription proxy at +8 */
    /* 0x14 */ void*     m_renderer;            /* polymorphic — see CAVEAT */
    /* 0x18 */ u8        _pad0018[0x08];
    /* 0x20 */ u32       m_controllerFilters[2];/* per-player input filter id */
    /* 0x28 */ u8        _pad0028[0x04];
    /* 0x2C */ s32       m_casMode;             /* current CAS mode */
    /* 0x30 */ u8        _padTail[0x40];        /* opaque tail */
};

/* ============================================================================
 * Function prototypes — matched CasMediator methods (subset; 15+ verified)
 * ========================================================================== */

/* Listener management (touch CasListenerSet base) */
extern "C" void f_80161D18(void); /* CasMediator::AddListener(...)            */
extern "C" int  f_80162028(void); /* CasMediator::GetListenerCount() — _M_node_count */

/* Sim editing */
extern "C" void f_801620D8(void); /* GetEditSimDescription() — m_editSim @ +0x10 */

/* Renderer-dispatched accessors (touch m_renderer @ +0x14) */
extern "C" void f_801620F4(void); /* GetNumBodyModels()                       */
extern "C" void f_80162128(void); /* GetNumTattooTextures()                   */
extern "C" void f_8016215C(void); /* GetIconTextureId()                       */
extern "C" void f_80162190(void); /* GetIconTattooTextureId()                 */
extern "C" void f_8016222C(void); /* DrawSim(...)                             */

/* Mode + controller filter (touch m_casMode + m_controllerFilters) */
extern "C" void f_8016226C(void); /* SetCasMode(int)                          */
extern "C" void f_801622F4(void); /* SetControllerFilterId(int player, u32 id)*/
extern "C" void f_8016230C(void); /* GetControllerFilterId(int player)        */

#endif /* SIMS2_TYPES_CASMEDIATOR_H */
