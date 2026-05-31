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

/* MODELING NOTE (validated — Matcher-SN-1, PushStringDictWord clean --strict
 * match @ commit 121f8f210): to reproduce SN's vtable+0x08 adjustor dispatch in
 * clean C++, declare AptValueObj as a polymorphic class with exactly TWO
 * non-virtual head words (m_flags, m_field04) BEFORE the first virtual method.
 * SN then places the vptr at +0x08 and makes the first virtual = slot 1, so a
 * call through it emits the native lha(adjustor s16 @vt+0x08)/lwz(fnptr @vt+0x0C)
 * /add/blrl sequence with no ASMPROC. Generalizes to any boxed/MI value type:
 * pad the head with N non-virtual words so the vptr lands at its observed
 * offset, and the desired virtual lands on the observed slot. */

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
 * AptValue — the 348-byte value (signature form). NOW PINNED (S19, evidence
 * from _FunctionAptActionStringDictByteGetVar 0x80280014, via Matcher-SN-1).
 *
 * KEY INSIGHT: AptValueObj (16B) and AptValue (348B) are the SAME conceptual
 * value type with a SHARED HEAD { type/flags @0x00, _ @0x04, vtable @0x08 } and
 * a VARIANT-SIZED payload starting at +0x0C:
 *   - immediate values (int/bool/float): 16-byte box, payload @0x0C is the
 *     scalar (this is AptValueObj above).
 *   - string values: 348-byte form, payload @0x0C is an INLINE char buffer
 *     holding the string text (which is why the struct is so large).
 * Both share vtable@0x08, so vtable-only operations (Push*DictByte/Word, stack
 * pushes, method dispatch) byte-match against EITHER form — confirmed: SN-1's
 * box-only matches still pass even though the dictionary actually stores 348B
 * AptValue*.
 *
 * Type discrimination (0x80280014):
 *   u32 t = obj->m_typeFlags & 0x7F;          // low 7 bits = type tag
 *   const char* name = (t == 1)               // type 1 == inline string
 *        ? (const char*)obj + 0x0C            //   text inline at +0x0C
 *        : (const char*)obj->m_ref + 0x0C;    //   else +0x24 -> backing, its +0x0C
 * i.e. +0x0C is the string text for inline values; for non-inline values, +0x24
 * holds a pointer to a backing AptValue whose +0x0C holds the text.
 * ========================================================================== */
struct AptValue {
    /* 0x00 */ u32             m_typeFlags; /* low 7 bits = type tag (1 = inline
                                              string; 12..19, 42..45 = other
                                              types per valueToObject). Shares
                                              meaning with AptValueObj::m_flags. */
    /* 0x04 */ u32             m_field04;   /* unknown (mirrors box +0x04).        */
    /* 0x08 */ AptValueVtable* m_vtable;    /* per-type dispatch (shared w/ box).  */
    /* 0x0C */ char            m_inlineStr[0x18]; /* type==1: inline C-string text
                                              begins here. For non-string types
                                              the same bytes carry a scalar/other
                                              payload (variant — do not assume). */
    /* 0x24 */ AptValue*       m_ref;       /* type!=1: pointer to a backing
                                              AptValue whose +0x0C holds the text.
                                              Overlaps the inline-string region as
                                              a type-discriminated variant.        */
    /* 0x28 */ u8              _body[0x134]; /* remainder of the inline-string
                                              capacity / variant body, opaque.
                                              Brings total size to 0x15C = 348.    */
};
/* sizeof(AptValue) == 348 (0x15C), matching the by-value signature size. */

/* NOTE on the overlap: m_inlineStr (from 0x0C) and m_ref (at 0x24) describe the
 * SAME storage interpreted by type — they are NOT simultaneously live. They are
 * declared as adjacent fields (not a C union) only so both offsets are
 * documented; a matcher should read whichever the type tag selects, exactly as
 * 0x80280014 does. Refcount idiom elsewhere (++/-- u16 @+0x00 of a *backing*
 * object, size @+0x04, free at zero) acts on referenced heap strings, not on an
 * AptValue's own header. */

#endif /* SIMS2_TYPES_APTVALUE_H */
