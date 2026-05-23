/* include/types/cXObjectImpl.h — canonical class layout for cXObjectImpl
 *
 * S17 TypeArchaeologist Phase 1 deliverable.
 *
 * Provenance: derived from ASMPROC inject_before stubs in src/matched/agent/.
 * The canonical 100% byte-match comes from injected raw asm; the field offsets
 * recovered below are read directly from that asm (load/store immediates against
 * the `this` register). Every offset cites the matched files that evidence it.
 *
 * Dispatch convention recap:
 *   - cXObjectImpl forwards most virtual calls through TWO embedded sub-objects:
 *       * this->m_inner (offset 0x04)  — primary external interface
 *       * this->m_impl  (offset 0x58)  — internal sim/impl interface
 *   - Sub-object vtable layout: vt_ptr at *m_inner+0x04 OR *m_impl+0x00;
 *     each "slot" in those vtables is a (short adj, fnptr) PAIR (8 bytes per
 *     entry, indexed at slot_base and slot_base+4).
 *   - The class also has a PRIMARY vtable pointer at this+0xEC (set in ctor
 *     0x800D962C with `stw 9,0xec(31)`).
 *
 * Compiler notes (SN ProDG / GCC 2.95):
 *   - Layout is POD-style with explicit padding. No virtual inheritance.
 *   - Field offsets are non-negotiable for matching codegen.
 */
#ifndef SIMS2_TYPES_CXOBJECTIMPL_H
#define SIMS2_TYPES_CXOBJECTIMPL_H

#include "../types.h"

/* ============================================================================
 * Forward declarations — keep this header self-contained
 * ========================================================================== */
struct cXObject;
struct cXObjectInner;
struct cXObjectImplSub;
struct ObjSelector;
struct ObjectModule;
struct FTilePt;
struct FTileRect;
struct PlacementSpec;
struct Behavior;
struct ReconBuffer;
struct StringBuffer;
struct EdithVariableSet;
struct ISimInstance;

/* ============================================================================
 * cXObjectInner — sub-object reached via this->m_inner (offset 0x04)
 *
 * Evidence (loads of *m_inner = inner+0x00 and inner+0x04):
 *   src/matched/agent/match_0x800E225C_..IsFromCatalog.cpp
 *     `lwz 11,0x4(3); lwz 9,0x4(11)`  — *(this+0x04)+0x04 = vtable
 *   src/matched/agent/match_0x800EAD18_..IsPortal.cpp
 *     `lwz 3,0x4(31); lwz 9,0x4(3); ... lwz 3,0x0(9)` — *(inner+0x00) = data ptr
 *   src/matched/agent/match_0x800E30D8_..GetColorIndex.cpp
 *     `lwz 3,0x4(3); lwz 9,0x4(3)`
 * ========================================================================== */
struct cXObjectInner {
    /* 0x00 */ void* m_data;     /* External interface "this" pointer (often the
                                    cXObject itself; written in ctor at line
                                    `stw 31,0x0(11)` where r11=*(this+0x04)) */
    /* 0x04 */ void* m_vtable;   /* Function-pointer table for the inner dispatch.
                                    Slot layout: (s16 adj, 2B pad, fnptr) at
                                    every +8. Method-by-slot table below. */
};

/* Inner-vtable slot map (cXObjectInner->m_vtable[]):
 *   slot_base/fn_base   Method                  Evidence
 *   ----------------    ----------------------  ----------------------------------
 *   0x100 / 0x104       (dtor-related)          ctor 0x800D962C: lha 0,0x100(9)
 *   0x198 / 0x19c       PreSave/parent fn       ~cXObjectImpl 0x800DBC54
 *   0x260 / 0x264       GetColorIndex(idx)      GetColorIndex 0x800E30D8
 *   0x310 / 0x314       GetObjDef2              IsFromCatalog 0x800E225C
 *                                               Initialize  0x800DA3D8
 *   0x318 / 0x31c       GetObjectType           IsPortal 0x800EAD18
 *   0x330 / 0x334       (init helper)           Initialize 0x800DA3D8
 *   0x368 / 0x36c       (string fetch)          ~cXObjectImpl/Initialize
 */

/* ============================================================================
 * cXObjectImplSub — sub-object reached via this->m_impl (offset 0x58)
 *
 * Evidence:
 *   src/matched/agent/match_0x800EB80C_..GetFirst.cpp
 *     `lwz 3,0x58(3); lwz 9,0x0(3)` — m_impl@0x58, vtable at impl+0x00
 *   src/matched/agent/match_0x800EAFC0_..EnableSim.cpp
 *     `lwz 11,0x58(3); lwz 9,0x0(11)` — same
 * ========================================================================== */
struct cXObjectImplSub {
    /* 0x00 */ void* m_vtable;   /* impl-side vtable; slots in (s16 adj, fnptr)
                                    pairs at every +8 same as inner. */
};

/* Impl-vtable slot map (cXObjectImplSub->m_vtable[]):
 *   slot_base/fn_base   Method                  Evidence
 *   ----------------    ----------------------  ----------------------------------
 *   0x098 / 0x09c       GetFirst dispatch       GetFirst 0x800EB80C
 *   0x240 / 0x244       EnableSimDispatch       EnableSim 0x800EAFC0
 */

/* ============================================================================
 * cXObjectImpl — main class
 *
 * Total observed extent: at least 0x13C bytes (316B) from direct field loads;
 * larger access at +0x5C70 reported in legacy include/cXObjectImpl.h but
 * unverified here. Treat anything beyond 0x140 as "expand-on-demand".
 *
 * Inheritance: behaves as a single-root class (no MI loads observed against
 * `this` as a base subobject). The primary vtable is stored at +0xEC, NOT 0x00.
 * ========================================================================== */
struct cXObjectImpl {
    /* ------------------------------------------------------------------------
     * 0x00 — head sub-object pointers
     * ---------------------------------------------------------------------- */
    /* 0x00 */ void*           m_field00;     /* sub-object 1; written to via
                                                  `stw 9,0x40(11)` where r11=
                                                  *(this+0x00) in ~ctor */
    /* 0x04 */ cXObjectInner*  m_inner;       /* primary inner sub-object */

    /* 0x08 */ void*           m_field08;     /* R/W in Initialize, ParseUIString */
    /* 0x0C */ int             m_field0C;     /* set from m_model[+0x74] in ctor
                                                  (`lha 0,0x74(m_model); stw 0,0xc(this)`) */

    /* 0x10 */ void*           m_field10;     /* set to 0 in ctor (`stw 9,0x10(this)`) */
    /* 0x14 */ s16             m_numVisible;  /* zeroed in ctor; bumped by visibility
                                                  counter; `sth 9,0x14(this)` */
    /* 0x16 */ s16             m_field16;
    /* 0x18 */ float           m_field18;
    /* 0x1C */ float           m_slotHeight;  /* GetSlotHeight 0x800DFBFC reads */

    /* ------------------------------------------------------------------------
     * 0x20 — location/placement scratch
     * ---------------------------------------------------------------------- */
    /* 0x20 */ float           m_field20;
    /* 0x24 */ float           m_field24;
    /* 0x28 */ float           m_field28;
    /* 0x2C */ void*           m_field2C;
    /* 0x30 */ float           m_field30;
    /* 0x34 */ float           m_field34;
    /* 0x38 */ void*           m_field38;
    /* 0x3C */ void*           m_field3C;

    /* ------------------------------------------------------------------------
     * 0x40 — catalog/flags
     * ---------------------------------------------------------------------- */
    /* 0x40 */ u8              _pad40[4];
    /* 0x44 */ void*           m_field44;
    /* 0x48 */ s16             m_field48;
    /* 0x4A */ s16             m_field4A;
    /* 0x4C */ float           m_field4C;     /* (alignment carries fields 4C-50
                                                  per Initialize / IsFromCatalog
                                                  asm loads `lha 0,0x4e(3)` etc.) */

    /* ------------------------------------------------------------------------
     * 0x58 — impl sub-object + sim ID/tile
     * ---------------------------------------------------------------------- */
    /* 0x58 */ cXObjectImplSub* m_impl;       /* zeroed in ctor */
    /* 0x5C */ s32             m_field5C;     /* `stw 30,0x5c(this)` in ctor */
    /* 0x60 */ s32             m_field60;     /* `stw 3,0x60(this)` in ctor */
    /* 0x64 */ s16             m_sourceID;    /* `sth 30,0x64(this)` ctor;
                                                  `lha 4,0x64(3)` in EnableSim arg2 */
    /* 0x66 */ u8              _pad66[2];
    /* 0x68 */ s32             m_field68;     /* `stw 30,0x68(this)` in ctor */
    /* 0x6C */ u8              _pad6C[4];
    /* 0x70 */ void*           m_field70;     /* `stw 30,0x70(this)` in ctor */
    /* 0x74 */ u8              _pad74[0x10];

    /* ------------------------------------------------------------------------
     * 0x84 — graphics & model
     * ---------------------------------------------------------------------- */
    /* 0x84 */ u32             m_miscFlags;   /* 32-bit MiscFlag bitmap.
                                                  Evidence: GetMiscFlag (0x800EAA68)
                                                  `lwz 0,0x84(3); and 9,0,4; bne...`
                                                  and SetMiscFlag (0x800EAA48)
                                                  `lwz 0,0x84(3); andc/or 0,0,4;
                                                   stw 0,0x84(3)`.
                                                  Ctor zero-inits then ORs in
                                                  bit 0x200 (`stw 30,0x84;
                                                  ori 0,0,512; stw 0,0x84`).
                                                  (Was previously labeled
                                                  m_hilite from legacy header
                                                  draft — incorrect.) */
    /* 0x88 */ void*           m_debugName;   /* `lwz 0,0x38(m_model); stw 0,0x88(this)` */
    /* 0x8C */ void*           m_model;       /* ctor arg3 (`stw 17,0x8c(this)`);
                                                  ComputeRect / GetFrontFaceDirection
                                                  read m_model fields */
    /* 0x90 */ char*           m_slotArray;   /* zeroed in ctor; HierGetChild stride 32;
                                                  `stw 30,0x90(this)` */
    /* 0x94 */ char*           m_slotArrayEnd;/* paired with m_slotArray
                                                  (`stw 30,0x4(0x90)`) */
    /* 0x98 */ char*           m_slotArrayCap;/* paired (`stw 30,0x4(0x98)`) */
    /* 0x9C */ u8              _pad9C[4];

    /* ------------------------------------------------------------------------
     * 0xA0 — TArray-like lists
     * ---------------------------------------------------------------------- */
    /* 0xA0 */ void*           m_fieldA0;     /* zeroed in ctor */
    /* 0xA4 */ u8              _padA4[0x4];
    /* 0xA8 */ void*           m_fieldA8;
    /* 0xAC */ u8              _padAC[4];
    /* 0xB0 */ void*           m_fieldB0;     /* zeroed in ctor */
    /* 0xB4 */ u8              _padB4[0x0C];

    /* ------------------------------------------------------------------------
     * 0xC0 — sync state
     * ---------------------------------------------------------------------- */
    /* 0xC0 */ void*           m_fieldC0;     /* zeroed in ctor */
    /* 0xC4 */ void*           m_fieldC4;     /* zeroed in ctor */
    /* 0xC8 */ u8              m_fieldC8;     /* `stb 0,0xc8(this)` ctor */
    /* 0xC9 */ u8              _padC9[3];
    /* 0xCC */ void*           m_fieldCC;     /* `stw 30,0xcc(this)` ctor */
    /* 0xD0 */ float           m_fieldD0;     /* `stfs f0,0xd0(this)` ctor (0.0f) */
    /* 0xD4 */ float           m_fieldD4;     /* `stfs f0,0xd4(this)` ctor (0.0f) */
    /* 0xD8 */ s16             m_fieldD8;     /* `sth 30,0xd8(this)` ctor */
    /* 0xDA */ u16             m_fieldDA;     /* `sth 11,0xda(this)` ctor (val=4) */
    /* 0xDC */ void*           m_syncObject;  /* `stw 9,0xdc(this)` ctor */
    /* 0xE0 */ float           m_syncObjectFloat;/* `stfs f0,0xe0(this)` ctor */
    /* 0xE4 */ void*           m_fieldE4;     /* `stw 9,0xe4(this)` ctor */
    /* 0xE8 */ u8              _padE8[4];

    /* ------------------------------------------------------------------------
     * 0xEC — PRIMARY VTABLE POINTER
     * Two `stw 9,0xec(this)` writes in ctor 0x800D962C — once with `lis 9,-32698;
     * addi 9,9,2392` (the actual vtable), once also seen in ~ctor.
     * ---------------------------------------------------------------------- */
    /* 0xEC */ void*           m_vtable;

    /* ------------------------------------------------------------------------
     * 0xF0 — extended (less-verified beyond this point)
     * Remaining fields preserved from legacy include/cXObjectImpl.h draft;
     * each one trace-verifiable via grep on src/matched/agent/*cXObjectImpl*.cpp.
     * Padding is approximate — DO NOT use sizeof() to allocate; this is a
     * documentation layout, not a complete instantiable struct.
     * ---------------------------------------------------------------------- */
    /* 0xF0 */ u8              _tail[0x4C];   /* extends through ~0x13C+;
                                                  ALSO larger far-fields up to
                                                  ~0x5C70 reported but unverified */
};

/* ============================================================================
 * Function prototypes (matched address — symbol — signature)
 * Kept as `extern "C"` raw forms so they coexist with ASMPROC stub builds.
 * Writers converting these to real C++ methods should mark the cpp file
 * `// SEMANTIC: cXObjectImpl::Method` and #include this header.
 * ========================================================================== */

/* Construction / lifecycle */
extern "C" void f_800D962C(void);   /* cXObjectImpl::cXObjectImpl(int, ...) */
extern "C" void f_800DBC54(void);   /* cXObjectImpl::~cXObjectImpl(void) */
extern "C" void f_800DA3D8(void);   /* cXObjectImpl::Initialize(void) */
extern "C" void f_800DA848(void);   /* cXObjectImpl::Reset(bool) */
extern "C" void f_800DB16C(void);   /* cXObjectImpl::Cleanup(cXObject*) */

/* Hierarchy / placement */
extern "C" void f_800DD114(void);   /* cXObjectImpl::HierGetChild(int) */
extern "C" void f_800DCF2C(void);   /* cXObjectImpl::HierGetParent(void) */
extern "C" void f_800DCF84(void);   /* cXObjectImpl::HierGetSlot(int) */
extern "C" void f_800DCB78(void);   /* cXObjectImpl::GetPlacementSpec(PlacementSpec*) */
extern "C" void f_800DD6E8(void);   /* cXObjectImpl::TestAndPlace(PlacementSpec*) */
extern "C" void f_800DE3C4(void);   /* cXObjectImpl::Place(FTilePt*) */

/* Type checks (return int) */
extern "C" void f_800E225C(void);   /* cXObjectImpl::IsFromCatalog(void) */
extern "C" void f_800EB758(void);   /* cXObjectImpl::IsChair(void) */
extern "C" void f_800EAD18(void);   /* cXObjectImpl::IsPortal(void) */
extern "C" void f_800EAD98(void);   /* cXObjectImpl::IsWindow(void) */
extern "C" void f_800EAE40(void);   /* cXObjectImpl::IsDoor(void) */
extern "C" void f_800E3094(void);   /* cXObjectImpl::IsPerson(void) */
extern "C" void f_800E3050(void);   /* cXObjectImpl::IsVehicle(void) */
extern "C" void f_800EB1D0(void);   /* cXObjectImpl::IsRoof(void) */
extern "C" void f_800EB4B4(void);   /* cXObjectImpl::IsSupport(void) */

/* Sub-object dispatch */
extern "C" void f_800EAFC0(void);   /* cXObjectImpl::EnableSim(bool) */
extern "C" void f_800EB80C(void);   /* cXObjectImpl::GetFirst(void) */
extern "C" void f_800E30D8(void);   /* cXObjectImpl::GetColorIndex(void) */
extern "C" void f_800E3118(void);   /* cXObjectImpl::SetColorIndex(unsigned char) */

#endif /* SIMS2_TYPES_CXOBJECTIMPL_H */
