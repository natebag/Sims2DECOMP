/* include/types/AptValue.h — canonical layout for the APT ActionScript value
 * representation (AptValue / its runtime value-box).
 *
 * S19 TypeArchaeologist reactive deliverable — services typereq:AptValue from
 * Matcher-SN-1 (info-board 3ed6d786), concrete blocker
 * _FunctionAptActionPushStringDictWord @ 0x8027F9A4.
 *
 * Provenance: every offset below is cited from ASMPROC stub asm of the
 * Push<constant> opcode handlers (PushByte 0x8028062C, PushFloat 0x80280504,
 * Push1 0x8027EFE8, PushTrue 0x8027F0E4) and PushStringDictWord 0x8027F9A4.
 * Shape-only header — no ASMPROC, no inline asm, no byte injection.
 *
 * ============================================================================
 * IMPORTANT — two distinct things share the name "AptValue"
 * ============================================================================
 * 1. **The runtime value-box** (this header's `AptValueObj`): a 16-byte,
 *    refcounted/GC-tracked, vtable-polymorphic heap object. THIS is what the
 *    interpreter actually pushes onto its stacks, stores in its string
 *    dictionary, and dispatches method calls through. Every Push* / stack /
 *    member / call opcode operates on POINTERS to these 16-byte boxes.
 *    It is fully pinned below.
 *
 * 2. **The 348-byte by-value `AptValue`** that appears in many C++ method
 *    signatures (e.g. `getVariable(AptValue)`). That is a SEPARATE, larger
 *    pass-by-value wrapper (likely a discriminated union with an inline string
 *    buffer). It is NOT fully spec'd here — its +0x00 word is read both as a
 *    type tag (valueToObject) and dereferenced as a pointer (getObject), so its
 *    internal union cannot be laid out without guessing. Only three offsets are
 *    known (documented at the bottom). Do NOT slice the 348B struct from this
 *    header; if you are matching a function that constructs/consumes the 348B
 *    by-value form, file typereq:AptValue_byval with that function's asm.
 *
 * SN-1's blocker (PushStringDictWord) uses only form #1 — the 16-byte box — so
 * AptValueObj fully unblocks it and the entire Push*/stack/dict opcode family.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_APTVALUE_H
#define SIMS2_TYPES_APTVALUE_H

#include "../types.h"

/* The per-type method table. Note the UNUSUAL slot encoding used by APT's
 * MI-adjustor dispatch (PushStringDictWord 0x8027F9A4, valueToObject 0x8026FF94):
 *   lwz  r11, 0x8(box)     ; box->m_vtable
 *   lha  r3,  0x8(r11)     ; (s16) this-adjustor at vtable+0x08
 *   lwz  r0,  0xC(r11)     ; fn pointer at vtable+0x0C
 *   add  r3,  box, r3      ; adjust `this`
 *   mtctr r0; bctrl        ; call
 * i.e. each callable vtable entry is { ... ; s16 adjustor @+0x08 ; fnptr @+0x0C }.
 * Other call sites read slot pairs at +0x10/0x14, +0x28/0x2C, +0x40/0x44 — same
 * (adjustor, fnptr) shape at different slots. Treat as opaque and reference by
 * the matched method; offsets here are for documentation. */
struct AptValueVtable; /* per-type dispatch table (Integer/Boolean/String/...) */

/* ============================================================================
 * AptValueObj — the 16-byte runtime value-box (APT's "boxed value").
 *
 * Allocation proof (PushByte 0x8028062C, empty-free-list path):
 *   lwz r3, -23020(r13)   ; heap
 *   li  r4, 16            ; sizeof == 16
 *   bl  <operator new>
 *   li  r4, 7             ; base-ctor type arg (7 = integer; 5 = boolean)
 *   bl  <AptValueObj ctor>
 *   stw <value>, 0xC(box) ; payload  @ +0x0C
 *   stw <vtable>, 0x8(box); m_vtable @ +0x08   (lis -32702; addi -24344 = int vt)
 *
 * Pool/GC proof (reuse path, shared by all Push*):
 *   lwz  r30, -269xx(r13) ; pop head of a per-type free list
 *   lwz  r9, 0xC(r30)     ; next-free link lives in the payload slot when free
 *   stw  r9, -269xx(r13)  ; advance free-list head
 *   oris r11, <flags>,8192; set GC mark bit 0x20000000 in m_flags
 *   stw  r11, 0x0(r30)    ; m_flags @ +0x00
 *   ; then append box to the GC sweep array at -27600(r13)
 *   stw  <value>, 0xC(r30); payload
 * ========================================================================== */
struct AptValueObj {
    /* 0x00 */ u32              m_flags;   /* type/GC word. Mark bits seen:
                                              0x20000000 (set on (re)use),
                                              0x08000000 (tested via andis. 2048
                                              elsewhere). Low bits carry a type
                                              discriminant in some paths. */
    /* 0x04 */ u32              m_field04; /* unknown — not written by the Push*
                                              handlers; possibly refcount or pool
                                              bookkeeping. Kept opaque, not guessed. */
    /* 0x08 */ AptValueVtable*  m_vtable;  /* per-type dispatch table (identity).
                                              Distinct rodata vtable per type:
                                              integer (lis -32702/addi -24344),
                                              boolean (lis -32702/addi -29224),
                                              string, etc. */
    /* 0x0C */ u32              m_payload; /* boxed value: int / float-bits inline,
                                              or a pointer for reference types.
                                              Doubles as the next-free link while
                                              the box sits in its pool free list. */
};
/* sizeof(AptValueObj) == 16, confirmed by the `li r4,16` allocation size. */

/* Base-ctor type argument observed (the `li r4,<n>` before the box ctor).
 * These name the constructed runtime type; they are NOT proven to equal the
 * low bits of m_flags, so they are kept as a documentation enum only. */
enum AptValueObjType {
    kAptValueObj_Boolean = 5,  /* PushTrue/PushFalse                */
    kAptValueObj_Integer = 7   /* PushByte/PushWord/PushDWord/Push1 */
    /* float / string / object / null / undefined types exist but their ctor
     * type numbers are not all sampled yet — extend as evidenced. */
};

/* ============================================================================
 * The 348-byte by-value AptValue (signature form) — NOT fully spec'd.
 *
 * Known offsets only (do not lay out the union from these):
 *   +0x00  word read as a type tag (valueToObject masks low 7 bits; observed
 *          type values 1, 12..19, 42, 43..45) AND dereferenced as a pointer
 *          in getObject — overloaded, so its meaning is context-dependent.
 *   +0x08  vtable pointer (polymorphic; valueToObject vcalls slot at +0x28/0x2C).
 *   +0x24  pointer field used when the type == 1.
 * Refcount idiom seen throughout (++/-- a u16 at +0x00 of a *backing* object,
 * size at +0x04, freed at zero) operates on the backing string/heap object the
 * AptValue references — not on the AptValue's own +0x00.
 *
 * If you need this struct, file typereq:AptValue_byval with the asm of the
 * specific function so the union can be pinned from real evidence.
 * ========================================================================== */

#endif /* SIMS2_TYPES_APTVALUE_H */
