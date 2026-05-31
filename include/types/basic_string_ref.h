/* include/types/basic_string_ref.h — canonical layout for the EA/STLport-style
 * ref-counted string representation: basic_string_ref (char / BString) and
 * basic_string_ref2 (wchar_t / BString2).
 *
 * S19 TypeArchaeologist deliverable — services MainGuy's proactive request to
 * unblock SN-2's BString/BString2 rep-allocation sub-family (operator=, reserve,
 * ctors, delete_ptr).
 *
 * Provenance: every offset/semantic cited from matched stub asm in
 * src/matched/{agent,bstring,bstring2}/ — the allocating ctor
 * basic_string_ref(unsigned,capacity) 0x8009C624, the copy-helper
 * basic_string_ref(BString&,uint,uint) 0x8009C71C, and the CLEAN matches
 * ctor(void) 0x8009C610, eos() 0x8009C608, delete_ptr() 0x8009BF5C,
 * ~basic_string_ref() 0x8009CA98. basic_string_ref2 confirmed parallel
 * (0x800A0770 ctor allocates len*2 for wchar; delete_ptr 0x800A00B8 identical).
 *
 * Shape-only header — no ASMPROC, no inline asm, no byte injection.
 *
 * ============================================================================
 * RELATIONSHIP to existing headers
 * ============================================================================
 * `basic_string_ref` IS the same 16-byte struct that include/types/BString2.h
 * documents as `BStringRep` (m_data@0x00, m_length@0x04, m_reserve@0x08,
 * m_ref_count@0x0C). This header is the canonical, full-signature version under
 * the real linker name. If you touch the rep directly, prefer the names here;
 * BString2.h's BStringRep is an alias of the same layout.
 *
 *   BString  (4-byte wrapper) = { basic_string_ref*  m_rep @ 0x00 }
 *   BString2 (4-byte wrapper) = { basic_string_ref2* m_rep @ 0x00 }
 * (Confirmed by the BString2.h evidence: the wrapper holds a single rep ptr;
 *  all length/data/refcount access is m_rep->field.)
 * ============================================================================
 */
#ifndef SIMS2_TYPES_BASIC_STRING_REF_H
#define SIMS2_TYPES_BASIC_STRING_REF_H

#include "../types.h"

struct BString;
struct BString2;

/* ============================================================================
 * basic_string_ref — the char (8-bit) ref-counted rep. 16 bytes.
 *
 * Layout (from 0x8009C624 ctor + 0x8009C610/0x8009C608/0x8009BF5C clean matches):
 *   ctor(unsigned n, capacity tag):
 *     tag==1 (reserve):  m_capacity = n; m_length = 0; if(n) m_data = alloc(n)
 *     tag==0 (sized):    m_length = n; m_capacity = n; if(n) { m_data=alloc(n);
 *                        fill n eos() chars; null-terminate } ; m_ref_count = 1
 *   delete_ptr(): if (m_capacity != 0) { Free(GetAllocator(), m_data);
 *                 m_capacity = 0; m_data = 0; }
 *   ~basic_string_ref(): delete_ptr();
 *   eos(): returns 0  (the '\0' terminator char value)
 * ========================================================================== */
struct basic_string_ref {
    /* 0x00 */ char* m_data;      /* heap char buffer (0 when empty/shared)      */
    /* 0x04 */ s32   m_length;    /* current string length                       */
    /* 0x08 */ s32   m_capacity;  /* allocated capacity; delete_ptr frees iff !=0 */
    /* 0x0C */ s32   m_ref_count; /* shared-rep refcount; ctor(void) increments   */

    /* Allocation interface (external — the 16B rep stores NO allocator; the
     * global heap is fetched per-call). Tool-resolved call targets
     * (tools/disasm_digest.sh on 0x8009C624 / 0x8009BF5C / 0x8009C71C):
     *   allocate : MainHeap()             [0x802CFF00, returns EAHeap*]
     *              -> EAHeap::Malloc(n,0) [0x802D0AA4]   (n bytes; see EAHeap.h)
     *   free     : MainHeap() -> EAHeap::Free(ptr) [0x802D0D78]
     *   copy     : memmove                [0x802434F8]
     *   data     : BString::data() const  [0x8009C020]
     *   eos      : basic_string_ref::eos()[0x8009C608] -> 0
     *   overflow : throwlength()          [0x8009BFAC]
     * Copy-helper (0x8009C71C) builds from a source string:
     *   basic_string_ref(BString& src, unsigned offset, unsigned count):
     *     m_length=count; m_capacity=(count? count+1 : count);
     *     if(count){ m_data = EAHeap::Malloc(MainHeap(), count+1);
     *                memmove(m_data, src.data()+offset, count);
     *                m_data[count]=eos(); } m_ref_count=1;
     * delete_ptr(): if(m_capacity){ EAHeap::Free(MainHeap(), m_data);
     *               m_capacity=0; m_data=0; }
     */
};
/* sizeof(basic_string_ref) == 16. */

/* ============================================================================
 * basic_string_ref2 — the wchar_t (16-bit) rep. 16 bytes. Layout identical to
 * basic_string_ref; m_data is wchar_t* and allocation is n*2 bytes
 * (0x800A0770: rlwinm r4,n,1 = n<<1). delete_ptr (0x800A00B8) identical logic.
 * ========================================================================== */
struct basic_string_ref2 {
    /* 0x00 */ u16*  m_data;      /* heap wchar_t buffer (0 when empty/shared)    */
    /* 0x04 */ s32   m_length;    /* current length in wchar elements             */
    /* 0x08 */ s32   m_capacity;  /* allocated capacity (elements); free iff !=0  */
    /* 0x0C */ s32   m_ref_count; /* shared-rep refcount                          */
};
/* sizeof(basic_string_ref2) == 16. */

/* ============================================================================
 * Function prototypes — matched rep methods (DVD-map addresses; files in
 * src/matched/{agent,bstring,bstring2}/). Most are FORCED → redo targets.
 * ========================================================================== */

/* ---- basic_string_ref (char) ---- */
extern "C" void f_8009C610(void); /* basic_string_ref()                          */
extern "C" void f_8009C624(void); /* basic_string_ref(unsigned, BString::capacity) */
extern "C" void f_8009C71C(void); /* basic_string_ref(BString&, unsigned, unsigned)*/
extern "C" void f_8009C7C4(void); /* basic_string_ref(char*, unsigned, unsigned)  */
extern "C" void f_8009C864(void); /* basic_string_ref(char*, unsigned)            */
extern "C" void f_8009C914(void); /* basic_string_ref(char*)                      */
extern "C" void f_8009C9D0(void); /* basic_string_ref(char, unsigned)             */
extern "C" void f_8009CA98(void); /* ~basic_string_ref()                          */
extern "C" void f_8009BF5C(void); /* delete_ptr()                                 */
extern "C" void f_8009C608(void); /* eos() -> 0                                   */
extern "C" void f_8009BFAC(void); /* throwlength()                               */
extern "C" void f_8009BFB0(void); /* throwrange()                                */

/* ---- basic_string_ref2 (wchar_t) ---- */
extern "C" void f_800A075C(void); /* basic_string_ref2()                         */
extern "C" void f_800A0770(void); /* basic_string_ref2(unsigned, capacity)        */
extern "C" void f_800A0870(void); /* basic_string_ref2(BString2&, unsigned, unsigned) */
extern "C" void f_800A093C(void); /* basic_string_ref2(unsigned, ...)            */
extern "C" void f_800A09E4(void); /* basic_string_ref2(unsigned, ...)            */
extern "C" void f_800A0A9C(void); /* basic_string_ref2(unsigned, ...)            */
extern "C" void f_800A0B60(void); /* basic_string_ref2(wchar_t, unsigned)        */
extern "C" void f_800A0C30(void); /* ~basic_string_ref2()                        */
extern "C" void f_800A00B8(void); /* basic_string_ref2::delete_ptr()             */
extern "C" void f_800A0754(void); /* basic_string_ref2::eos() -> 0               */
extern "C" void f_800A0108(void); /* basic_string_ref2::throwlength()            */
extern "C" void f_800A010C(void); /* basic_string_ref2::throwrange()             */

#endif /* SIMS2_TYPES_BASIC_STRING_REF_H */
