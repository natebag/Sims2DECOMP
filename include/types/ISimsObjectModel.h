/* include/types/ISimsObjectModel.h — canonical layout for ISimsObjectModel
 *                                     and its derived interface family
 *
 * S17 TypeArchaeologist Phase 1 deliverable #6.
 *
 * Provenance: SEMANTIC-style matched .cpp files in src/matched/iobject/
 * (these are real handwritten C++ that produces byte-identical output,
 * unlike most matched files which are ASMPROC stubs — see GetDynamic,
 * SetPos, SetDir, Create for inheritance + offset evidence).
 *
 * ============================================================================
 * Family shape (multiple inheritance with secondary-vtable mixin)
 *
 *   ISimsObjectModel               (base — primary vtable at +0x00)
 *     |
 *     +-- ISimsWallObjectModel     (adds m_vtable2 at +0x320 to mix in a
 *     +-- ISimsCounterTopObject     "wall/counter-top/multi-tile/shrub" role
 *     +-- ISimsMultiTileObjectModel  via a SECONDARY vtable; this is the SN
 *     +-- IShrubObject               ProDG MI-thunk shape)
 *
 *   Each derived ctor is uniform (~72B):
 *     <Derived>::<Derived>() : ISimsObjectModel() {
 *         m_vtable2 = <Derived>_vtable2;
 *         *(int **)this = <Derived>_vtable;   // overwrite primary vtable
 *     }
 *   See src/matched/iobject/match_80051170 (Wall), match_800520AC (Counter),
 *   match_80051A8C (MultiTile), match_800525E4 (Shrub) for the proof set.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_ISIMSOBJECTMODEL_H
#define SIMS2_TYPES_ISIMSOBJECTMODEL_H

#include "../types.h"
#include "EVec3.h"

/* Forward decls */
struct cXObject;
struct EHouse;

/* Note on EVec3 ABI: m_pos / m_dir are integer-coord vectors (world-grid
 * Sims coordinate space), so they use the canonical `EVec3i` type from
 * EVec3.h — NOT the float-form `EVec3` used by graphics/physics/animation.
 * Evidence: src/matched/iobject/match_0x80053DE0 (SetPos) and
 * match_0x80053E08 (SetDir) declare `struct EVec3 { int x, y, z; }` locally
 * and compile to int lwz/stw triplets. See include/types/EVec3.h for the
 * full reconciliation story.
 *
 * Pre-S18 versions of this file used a local `ISOM_EVec3` typedef as a
 * workaround; that has been removed in favour of canonical `EVec3i`. */

/* ============================================================================
 * ISimsObjectModel — base interface for object models
 *
 * Verified offsets (all from semantic-style matched files):
 *   0x000  vtable (primary)        — set by derived ctor with
 *                                    `*(int**)this = <Derived>_vtable`
 *   0x320  m_vtable2 (secondary)   — secondary vtable for MI thunk;
 *                                    set in derived ctor
 *   0x324  m_xobj (cXObject*)      — ISimsCounterTopObject::Create
 *                                    (src/matched/iobject/match_80052154)
 *   0x32C  m_field_32C (u32)       — bitmap; bit 6 = "dynamic" flag.
 *                                    GetDynamic returns (m_field_32C >> 6) & 1
 *                                    (src/matched/iobject/match_0x80053DA4)
 *   0x3C4  m_house (EHouse*)       — Create sets m_house = arg
 *                                    (Create stub: this+0x3C4 — derived from
 *                                    pad layout in match_80052154)
 *   0x404  m_pos (EVec3 of ints)   — SetPos copies vec to this+0x404
 *                                    (src/matched/iobject/match_0x80053DE0)
 *   0x410  m_dir (EVec3 of ints)   — SetDir copies vec to this+0x410
 *                                    (src/matched/iobject/match_0x80053E08)
 *
 * Total size unverified — extends at least through 0x41C. Treat as opaque
 * tail beyond m_dir.
 * ========================================================================== */
struct ISimsObjectModel {
    /* 0x000 */ void*       m_vtable;
    /* 0x004 */ u8          _pad004[0x31C];

    /* 0x320 */ void*       m_vtable2;       /* secondary vtable for MI thunk */
    /* 0x324 */ cXObject*   m_xobj;
    /* 0x328 */ u8          _pad328[4];

    /* 0x32C */ u32         m_field_32C;     /* misc bitmap; bit 6 = dynamic
                                                 (GetDynamic). Other bits used
                                                 by setter/clearers in iobject
                                                 stubs match_8005X*. */

    /* 0x330 */ u8          _pad330[0x94];

    /* 0x3C4 */ EHouse*     m_house;         /* Create writes m_house = arg */

    /* 0x3C8 */ u8          _pad3C8[0x3C];

    /* 0x404 */ EVec3i  m_pos;           /* SetPos                          */
    /* 0x410 */ EVec3i  m_dir;           /* SetDir                          */

    /* 0x41C */ u8          _padTail[0x40];  /* opaque tail                     */
};

/* ============================================================================
 * Derived classes — all share the same pad-then-vtable2 layout
 * (use these aliases for ctor/dtor signatures; the unique state of each
 * derived is in additional vtable slots, not extra fields)
 * ========================================================================== */
struct ISimsWallObjectModel     : public ISimsObjectModel {};
struct ISimsCounterTopObject    : public ISimsObjectModel {};
struct ISimsMultiTileObjectModel: public ISimsObjectModel {};
struct IShrubObject             : public ISimsObjectModel {};

/* External symbols (vtables — declared so ctor-port writers can reference
 * them without re-deriving per-file). */
extern "C" int ISimsObjectModel_vtable[];
extern "C" int ISimsObjectModel_vtable2[];
extern "C" int ISimsWallObjectModel_vtable[];
extern "C" int ISimsWallObjectModel_vtable2[];
extern "C" int ISimsCounterTopObject_vtable[];
extern "C" int ISimsCounterTopObject_vtable2[];
extern "C" int ISimsMultiTileObjectModel_vtable[];
extern "C" int ISimsMultiTileObjectModel_vtable2[];
extern "C" int IShrubObject_vtable[];
extern "C" int IShrubObject_vtable2[];

/* ============================================================================
 * Sample matched method prototypes (address — symbol — file)
 * ========================================================================== */

/* Trivial accessors — already SEMANTIC-converted in src/matched/iobject/ */
extern "C" int  f_80053DA4(void); /* ISimsObjectModel::GetDynamic()        */
extern "C" int  f_80053E60(void); /* ISimsObjectModel::ShouldAnimStartImmediate(u32) */
extern "C" int  f_80053E74(void); /* ISimsObjectModel::ShouldKillAllAnimTracks()    */
extern "C" void f_80053DE0(void); /* ISimsObjectModel::SetPos(EVec3&)               */
extern "C" void f_80053E08(void); /* ISimsObjectModel::SetDir(EVec3&)               */
extern "C" void f_8004EB6C(void); /* ISimsObjectModel::SetPosStatic(EVec3&, float)  */
extern "C" void f_8004ED20(void); /* ISimsObjectModel::SetOutOfWorld()              */
extern "C" void f_8004ED24(void); /* ISimsObjectModel::StartBurp()                  */

/* Lifecycle (derived ctors that overwrite primary vtable) */
extern "C" void f_80051170(void); /* ISimsWallObjectModel::ISimsWallObjectModel()   */
extern "C" void f_800511B8(void); /* ISimsWallObjectModel::~ISimsWallObjectModel()  */
extern "C" void f_80051A8C(void); /* ISimsMultiTileObjectModel::ctor                */
extern "C" void f_80051AD4(void); /* ISimsMultiTileObjectModel::dtor                */
extern "C" void f_800520AC(void); /* ISimsCounterTopObject::ctor                    */
extern "C" void f_800520F4(void); /* ISimsCounterTopObject::dtor                    */
extern "C" void f_80052154(void); /* ISimsCounterTopObject::Create(cXObject*, EHouse*) */
extern "C" void f_800525E4(void); /* IShrubObject::ctor                              */
extern "C" void f_8005262C(void); /* IShrubObject::dtor                              */

/* Big-body methods (still ASMPROC stubs — see src/matched/agent/) */
extern "C" void f_8004CBDC(void); /* ISimsObjectModel::Update()                     */
extern "C" void f_8004FE28(void); /* ISimsObjectModel::Draw(ELevelDrawData*)        */
extern "C" void f_80050CA0(void); /* ISimsObjectModel::Create(cXObject*)            */
extern "C" void f_8004FC24(void); /* ISimsObjectModel::IsVisible()                  */
extern "C" void f_8004FBA0(void); /* ISimsObjectModel::VisibilityTest(E3DWindow*)   */
extern "C" void f_8004D6CC(void); /* ISimsObjectModel::SetupCharacter()             */
extern "C" void f_80050B00(void); /* ISimsObjectModel::SetInitalObjectState()       */
extern "C" void f_80050418(void); /* ISimsObjectModel::DrawBounds(ERC*)             */
extern "C" void f_80050D44(void); /* ISimsObjectModel::SetObjOrient()               */
extern "C" void f_80050EB4(void); /* ISimsObjectModel::OrientSubObjects()           */

#endif /* SIMS2_TYPES_ISIMSOBJECTMODEL_H */
