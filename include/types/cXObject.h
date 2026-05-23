/* include/types/cXObject.h — canonical class layout for cXObject
 *
 * S17 TypeArchaeologist Phase 1 deliverable #2.
 *
 * Provenance: derived from ASMPROC inject_before stubs in src/matched/agent/.
 *
 * Conceptual relationship to cXObjectImpl (CRITICAL — read before using):
 *   cXObject is NOT a base class that cXObjectImpl inherits from.
 *   cXObject is a LIGHTWEIGHT REGISTRY/WRAPPER that holds pointers to the four
 *   "impl variants" via an embedded `ImplHolder` sub-object:
 *       - cXObjectImpl*    (general objects, e.g. furniture)
 *       - cXPersonImpl*    (Sims)
 *       - cXMTObjectImpl*  (multi-tile, e.g. counters, beds)
 *       - cXPortalImpl*    (doors, windows)
 *   The actual heavyweight state (slot arrays, sync objects, behavior trees,
 *   etc.) lives in the impl objects, not in cXObject.
 *
 *   The four `cXObject::set<X>Impl(<X>* impl)` methods (0x800EA98C, 0x800EA998,
 *   0x800EA9A4, 0x800EA9B0) all share the same form:
 *       lwz r9, 0x0(r3)   ; r9 = this->m_implHolder
 *       stw r4, 0x<N>(r9) ; m_implHolder->m_<X>Impl = arg
 *   confirming the ImplHolder layout below.
 */
#ifndef SIMS2_TYPES_CXOBJECT_H
#define SIMS2_TYPES_CXOBJECT_H

#include "../types.h"

/* Forward declarations — kept light to avoid circular includes */
struct cXObjectImpl;
struct cXPersonImpl;
struct cXMTObjectImpl;
struct cXPortalImpl;
struct cXObjectImplHolder;

/* ============================================================================
 * cXObjectImplHolder — the embedded impl-pointer registry
 *
 * Lives at cXObject + 0x08 by default (m_implHolder defaults to point at the
 * embedded copy; see ctor 0x800EA894:
 *     addi r0, r31, 0x8   ; r0 = this + 0x8
 *     stw  r0, 0x0(r31)   ; m_implHolder = &m_implData
 *     mr   r3, r0
 *     bl   <_s800EA894_0> ; sub-ctor on the embedded holder
 *
 * Slots 0..0x0C evidence (cXObject::setXxxImpl stubs):
 *   0x00 setObjectImpl    src/matched/agent/match_0x800EA98C_..setObjectImpl..cpp
 *                         `lwz 9,0x0(3); stw 4,0x0(9)`
 *   0x04 setPersonImpl    src/matched/agent/match_0x800EA998_..setPersonImpl..cpp
 *                         `lwz 9,0x0(3); stw 4,0x4(9)`
 *   0x08 setMTObjectImpl  src/matched/agent/match_0x800EA9A4_..setMTObjectImpl..cpp
 *                         `lwz 9,0x0(3); stw 4,0x8(9)`
 *   0x0C setPortalImpl    src/matched/agent/match_0x800EA9B0_..setPortalImpl..cpp
 *                         `lwz 9,0x0(3); stw 4,0xc(9)`
 *
 * Slots 0x10, 0x14, 0x18 evidence (cXObject::~cXObject 0x800D9484):
 *   stw  0, 0x10(r11)   ; r11 = m_implHolder    -> m_field10 = NULL
 *   stw  0, 0x14(r9)    ; r9  = m_implHolder    -> m_field14 = 0
 *   stw  r7, 0x18(r11)  ; m_arrayVtable = vt
 *
 * Tail (0x1C..0xC0): 168-byte (0xA8) buffer initialized via memcpy of a static
 * default in cXObject::cXObject(int) (the `1:` loop block). Format unverified
 * beyond "TArray<>-style inline data with vtable at +0x18".
 * ========================================================================== */
struct cXObjectImplHolder {
    /* 0x00 */ cXObjectImpl*   m_objectImpl;
    /* 0x04 */ cXPersonImpl*   m_personImpl;
    /* 0x08 */ cXMTObjectImpl* m_mtObjectImpl;
    /* 0x0C */ cXPortalImpl*   m_portalImpl;
    /* 0x10 */ void*           m_field10;
    /* 0x14 */ s32             m_field14;
    /* 0x18 */ void*           m_arrayVtable;
    /* 0x1C */ u8              m_arrayBuf[0xA8];
    /* total: 0xC4 (alignment may push to 0xC8) */
};

/* ============================================================================
 * cXObject — the wrapper
 *
 * Total head size: 0x08 (just the two head pointers). With the embedded
 * holder, full instance size is 0x08 + sizeof(cXObjectImplHolder) ~= 0xCC.
 *
 * NOTE on the primary vtable at +0x04:
 *   The cXObject ctor stores `0x80060FB0` (vtable in rodata) at this+0x04:
 *       lis  r9, -32698 ; high 16 = 0x8006_0000 (sign-extended from 0x8006)
 *       addi r9, r9, 4016
 *       stw  r9, 0x4(r31)
 *   This means cXObject HAS a vtable pointer at offset 0x04, NOT 0x00, and
 *   the slot at 0x00 holds a data pointer to the embedded ImplHolder. SN ProDG
 *   does this so that variable-virtual code paths can dereference `*this` as
 *   data without skipping over a vtable cell.
 * ========================================================================== */
struct cXObject {
    /* 0x00 */ cXObjectImplHolder* m_implHolder; /* defaults to &m_implData */
    /* 0x04 */ void*               m_vtable;     /* set in ctor to rodata vtable
                                                    at 0x80060FB0 */
    /* 0x08 */ cXObjectImplHolder  m_implData;   /* embedded; size ~0xC4 */
};

/* ============================================================================
 * Static / non-instance helpers
 *
 * Several cXObject methods are STATIC: they read/write SDA globals or call into
 * the singleton chain rather than touching `this`. Confirmed by inspection of
 * the stub asm: no `lwz/stw <reg>, 0x..(3)` form against this.
 * ========================================================================== */

/* cXObject::SetFreeWill(bool) at 0x800DB954:
 *   stw r3, -31912(r13)       ; sda store of bool
 *   lwz r11, -21496(r13)      ; sda load of manager singleton
 *   if (mgr) { vcall mgr.slot[7] (offset 0x38/0x3c) with (mgr, 30, short@-31910) } */
extern "C" void f_800DB954(void); /* cXObject::SetFreeWill(bool) */

/* cXObject::SetGlobalFreeWillOverride(bool)  at 0x800DB9A0 */
extern "C" void f_800DB9A0(void);

/* cXObject::GetGlobalInitTreeID(void)        at 0x800D961C */
extern "C" void f_800D961C(void);
/* cXObject::GetGlobalMainTreeID(void)        at 0x800D9624 */
extern "C" void f_800D9624(void);

/* Auto* getters/setters (small SDA-touching statics) */
extern "C" void f_800D95EC(void); /* cXObject::GetPersonWidth(void) */
extern "C" void f_800D95F4(void); /* cXObject::GetFreeWill(void) */
extern "C" void f_800D95FC(void); /* cXObject::GetAutoCenter(void) */
extern "C" void f_800D9604(void); /* cXObject::SetAutoCenter(bool) */
extern "C" void f_800D960C(void); /* cXObject::GetAutoReset(void) */
extern "C" void f_800D9614(void); /* cXObject::SetAutoReset(bool) */

/* Construction / destruction */
extern "C" void f_800EA894(void); /* cXObject::cXObject(int) */
extern "C" void f_800D9484(void); /* cXObject::~cXObject(void) */
extern "C" void f_800EA9BC(void); /* cXObject::CAST_IMPL(void) — RTTI helper */

/* Impl registration */
extern "C" void f_800EA98C(void); /* cXObject::setObjectImpl(cXObjectImpl*) */
extern "C" void f_800EA998(void); /* cXObject::setPersonImpl(cXPersonImpl*) */
extern "C" void f_800EA9A4(void); /* cXObject::setMTObjectImpl(cXMTObjectImpl*) */
extern "C" void f_800EA9B0(void); /* cXObject::setPortalImpl(cXPortalImpl*) */

/* ============================================================================
 * cXObject::MiscFlag enum + access
 *
 * Stored as a 32-bit bitmap in cXObjectImpl at offset 0x84 (NOT in cXObject —
 * the symbol prefix on these methods is `cXObjectImpl::` because the actual
 * storage lives in the impl). SetMiscFlag/GetMiscFlag stubs evidence the bit
 * ops:
 *   GetMiscFlag (0x800EAA68): `lwz 0,0x84(3); and 9,0,4; bne ...`
 *   SetMiscFlag (0x800EAA48): `lwz 0,0x84(3); cmplwi 5,0; andc 0,0,4;
 *                              stw 0,0x84(3); beqlr; or 0,0,4; stw 0,0x84(3)`
 *
 * (cXObjectImpl.h needs a follow-up edit to relabel m_hilite@0x84 → m_miscFlags.)
 * ========================================================================== */
extern "C" void f_800EAA48(void); /* cXObjectImpl::SetMiscFlag(MiscFlag, bool) */
extern "C" void f_800EAA68(void); /* cXObjectImpl::GetMiscFlag(MiscFlag) */

#endif /* SIMS2_TYPES_CXOBJECT_H */
