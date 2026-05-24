/* include/types/BString2.h — canonical layout for BString2 + BStringRep
 *
 * S18 TypeArchaeologist deliverable. EVIDENCE-FIRST SYNTHESIS (not legacy
 * promotion) — the legacy include/classes/BString2.h is WRONG: it documents
 * a 16-byte BString2 class with multiple fields, but byte-match evidence
 * proves BString2 is a 4-byte wrapper around a separate BStringRep struct.
 * The 16-byte layout in the legacy header is actually BStringRep, mis-
 * attributed to BString2.
 *
 * Authored S18 post-KimiWorker-incident (postmortem info-post `postmortem`
 * id a2da1ccb). KimiWorker's ref_count/point/len fake-struct converts
 * (commit 7b4992361, reverted at 00f6d2936) failed byte-match because of
 * register-allocation drift caused by raw-cast pointer arithmetic instead
 * of struct-member access. This canonical header provides the correct
 * pattern.
 *
 * ============================================================================
 * BYTE-MATCH EVIDENCE for BStringRep layout (from agent/ stub asm):
 *
 *   ref_count @ 0x800A0170 (12B):
 *     lwz 9,0x0(3); lwz 3,0xc(9)
 *     → r9 = m_rep; r3 = m_rep[0x0C] = m_ref_count    [m_ref_count @ +0x0C]
 *
 *   point @ 0x800A017C (12B):
 *     lwz 9,0x0(3); lwz 3,0x0(9)
 *     → r9 = m_rep; r3 = m_rep[0x00] = m_data         [m_data      @ +0x00]
 *
 *   len @ 0x800A0188 (12B):
 *     lwz 3,0x0(3); addi 3,3,4
 *     → r3 = m_rep + 0x04 = &m_length (returns int*)  [m_length    @ +0x04]
 *
 *   m_reserve @ +0x08 inferred from cluster (no direct asm yet; plausible
 *   for a ref-counted string with separate length + capacity tracking).
 * ============================================================================
 *
 * **BYTE-MATCH CONVERSION GUIDANCE (READ BEFORE WRITING ANY BString2 CONVERT)**
 *
 * The KimiWorker BString2 incident (commit 7b4992361, reverted) was caused
 * by raw-cast fake-struct deviation. To avoid repeating:
 *
 * 1. **#include "types/BString2.h"** — use canonical BString2 + BStringRep.
 *    Do NOT redeclare locally with a different name or with raw `void*`
 *    fields where struct-pointer fields belong.
 *
 * 2. **Use struct-member access, NOT raw pointer arithmetic.**
 *    The smoking gun from KimiWorker's failed ref_count:
 *      Fake:    int* p = (int*)m_buffer; return p[3];
 *               → compiler reuses r3 for intermediate:
 *                  lwz r3, 0(r3); lwz r3, 0xC(r3); blr
 *      Correct: return m_rep->m_ref_count;
 *               → compiler uses r9 intermediate (matches DOL):
 *                  lwz r9, 0(r3); lwz r3, 0xC(r9); blr
 *    Same instruction count, DIFFERENT register allocation = byte miss.
 *    The struct-member access pattern is REQUIRED for byte-match.
 *
 * 3. **Method-signature ABI must match DOL.** For trivial accessors,
 *    return type matters — `int*` return for `len()` is what the asm
 *    proves (returns &m_length, not m_length value). Do not collapse
 *    to value-return.
 *
 * 4. **Legacy include/classes/BString2.h is wrong** — don't reference
 *    its 16-byte layout. That's BStringRep, not BString2.
 *
 * If you suspect a method signature gap, POST a typereq don't fake-struct.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_BSTRING2_H
#define SIMS2_TYPES_BSTRING2_H

#include "../types.h"

/* ============================================================================
 * BStringRep — 16-byte ref-counted backing store for BString2
 *
 * Layout (per ref_count/point/len asm evidence):
 *   0x00 void* m_data        (UTF-16 wchar_t* buffer; or other char-data ptr)
 *   0x04 s32   m_length      (current string length)
 *   0x08 s32   m_reserve     (allocated capacity; inferred from cluster)
 *   0x0C s32   m_ref_count   (reference count for COW sharing)
 *
 * NOTE: this is the layout the legacy include/classes/BString2.h
 * mis-attributed to BString2 itself. The legacy header had 4 fields
 * at +0x00/+0x02/+0x04/+0x0C with field types u16/u16/u32/u32 — that
 * shape was a misread. The correct shape is (void*, int, int, int) =
 * 16 bytes living inside BStringRep, accessed via BString2.m_rep ptr.
 * ========================================================================== */
struct BStringRep {
    /* 0x00 */ void* m_data;
    /* 0x04 */ s32   m_length;
    /* 0x08 */ s32   m_reserve;     /* inferred */
    /* 0x0C */ s32   m_ref_count;
};

/* ============================================================================
 * BString2 — 4-byte ref-counted wide-string wrapper
 *
 * Total size: 4 bytes (single ptr m_rep). COW sharing semantics via m_rep's
 * m_ref_count.
 *
 * Symbol-map evidence: 187 methods total per legacy header roster (see
 * sample method declarations below; full set in extracted/files/
 * u2_ngc_release.map under `BString2::`).
 * ========================================================================== */
class BString2 {
public:
    /* 0x00 */ BStringRep* m_rep;

    /* ---- Construction / destruction ---- */
    BString2(void);                                          /* 0x801F8878  */
    BString2(u16* str);                                      /* 0x801F8B94  */
    BString2(u32, BString2 /*capacity tag*/);                /* 0x801F88C4  */
    BString2(BString2& other, u32 pos, u32 count);            /* 0x801F8940  */
    BString2(u16* str, u32 pos, u32 count);                  /* 0x801F8A70  */
    BString2(u16* str, u32 len);                             /* 0x801F8B18  */
    BString2(wchar_t c, u32 count);                          /* 0x801F8C08  */
    ~BString2(void);                                          /* 0x801F8C90  */

    /* ---- Ref-counted internal accessors (12B each, asm-verified) ---- */
    s32   ref_count(void) const;                              /* 0x800A0170  */
    void* point(void) const;                                  /* 0x800A017C  */
    s32*  len(void) const;                                    /* 0x800A0188  */
    void  delete_ref(void);                                   /* 0x801F5FC0  */

    /* ---- Public accessors ---- */
    u16*  wchar_str(void);                                   /* 0x80095C5C  */
    char* c_str(void);                                       /* 0x801FAB9C  */
    s32   length(void) const;                                /* 0x801FC720  */
    void* data(void);                                        /* 0x801FCBE4  */
    bool  empty(void) const;                                 /* 0x80232A4C  */
    s32   size(void) const;                                  /* 0x8054EABC  */
    s32   reserve(void) const;                               /* 0x801FC750  */

    /* ---- Element access ---- */
    wchar_t get_at(u32 pos);                                 /* 0x801F60BC  */
    void    put_at(u32 pos, wchar_t c);                      /* 0x801FA920  */
    wchar_t operator[](u32 pos);                              /* 0x801FAAA0  */

    /* ---- Assignment ---- */
    BString2& operator=(u16* str);                           /* 0x801F8DD4  */
    BString2& operator=(BString2& other);                    /* 0x801F8D00  */
    BString2& operator=(wchar_t c);                          /* 0x801F8E2C  */
    void      assignDebug(char* str);                        /* 0x801FC780  */
    void      assign(u16* str);                              /* 0x801F9688  */
    void      assign(u16* str, u32 len);                     /* 0x801F9638  */
    void      assign(BString2& other, u32 pos, u32 count);    /* 0x801F9514  */
    void      assign(wchar_t c, u32 count);                  /* 0x801F96E0  */
    void      assign_str(u16* str, u32 len);                 /* 0x801F72F4  */

    /* ---- Concat / append ---- */
    BString2& operator+=(BString2& other);                   /* 0x801F8F3C  */
    BString2& operator+=(u16* str);                          /* 0x801F8FA0  */
    BString2& operator+=(wchar_t c);                          /* 0x801F8FF8  */
    void      append(u16* str);                              /* 0x801F92B4  */
    void      append(u16* str, u32 len);                     /* 0x801F9264  */
    void      append(BString2& other, u32 pos, u32 count);    /* 0x801F919C  */
    void      append(wchar_t c, u32 count);                  /* 0x801F930C  */
    void      append_str(u16* str, u32 len);                 /* 0x801F7454  */

    /* ---- Insert / erase / replace / remove / resize ---- */
    void insert(u32 pos, BString2& other, u32 sub_pos, u32 sub_count);  /* 0x801F986C */
    void insert(u32 pos, u16* str, u32 len);                 /* 0x801F9940  */
    void insert(u32 pos, u16* str);                          /* 0x801F9998  */
    void insert(u32 pos, wchar_t c, u32 count);              /* 0x801F99F8  */
    void insert_str(u32 pos, u16* str, u32 len);             /* 0x801F7618  */
    void erase(u32 pos, u32 count);                          /* 0x801F9E04  */
    void remove(u32 pos, u32 count);                         /* 0x800A7E18  */
    void replace(u32 pos, u32 count, u16* str);              /* 0x801FA280  */
    void replace(u32 pos, u32 count, u16* str, u32 len);     /* 0x801FA1E0  */
    void replace(u32 pos, u32 count, BString2& other, u32 sub_pos, u32 sub_count); /* 0x801FA0C4 */
    void replace(u32 pos, u32 count, wchar_t c, u32 ch_count); /* 0x801FA328 */
    void replace_str(u32 pos, u32 count, u16* str, u32 len); /* 0x801F796C  */
    void resize(u32 new_size);                               /* 0x801FADC0  */
    void resize(u32 new_size, wchar_t fill);                 /* 0x801FAC00  */
    void reserve(u32 new_cap);                               /* 0x801FAE0C  */

    /* ---- Substring + copy ---- */
    void substr(u32 pos, u32 count);                         /* 0x801FBBA4  */
    void copy(u16* dst, u32 count, u32 pos);                 /* 0x801FAED8  */

    /* ---- Find family (extensive — sample subset; see legacy/map for full) ---- */
    s32 find(wchar_t c, u32 start);                          /* 0x801FB0EC  */
    s32 find(u16* str, u32 start);                           /* 0x801FB088  */
    s32 find(BString2& other, u32 start);                    /* 0x801FAFBC  */
    s32 find(u16* str, u32 start, u32 len);                  /* 0x801FB02C  */
    s32 rfind(wchar_t c, u32 start);                          /* 0x801FB2E8  */
    s32 rfind(BString2& other, u32 start);                    /* 0x801FB1B8  */
    s32 find_first_of(wchar_t c, u32 start);                  /* 0x801FB550  */
    s32 find_last_of(wchar_t c, u32 start);                   /* 0x801FB6E0  */
    s32 find_first_not_of(wchar_t c, u32 start);              /* 0x801FB870  */
    s32 find_last_not_of(wchar_t c, u32 start);               /* 0x801FBA6C  */
    s32 find_str(u16* str, u32 start, u32 len);              /* 0x801F7EFC  */
    s32 rfind_str(u16* str, u32 start, u32 len);             /* 0x801F80F4  */

    /* ---- Compare ---- */
    s32 compare(BString2& other, u32 pos, u32 count);        /* 0x801FBC98  */
    s32 compare(u16* str, u32 len);                          /* 0x801FBDD8  */
    s32 compare(u16* str, u32 pos, u32 len);                 /* 0x801FBD50  */
    s32 compare(wchar_t c, u32 pos, u32 count);               /* 0x801FBE54  */
    s32 compare_str(u32 self_pos, u16* str, u32 str_pos, u32 len); /* 0x801F7DCC */
    bool operator==(BString2& other);                         /* 0x801FC604  */
    bool operator!=(BString2& other);                         /* 0x801FC664  */
    bool operator<(BString2& other);                          /* 0x801FC6C8  */

    /* ---- Internal state ---- */
    bool eos(void);                                           /* 0x801F72B8  */
};

#endif /* SIMS2_TYPES_BSTRING2_H */
