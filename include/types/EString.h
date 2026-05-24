/* include/types/EString.h — canonical layout for EString family
 *
 * S18 TypeArchaeologist deliverable. Opportunistic legacy promotion of
 * include/core/e_string.h (mature draft). EString / EString2 / EFixedString
 * + TArray template + explicit TArray<EString*> specializations.
 *
 * Source TU: e_string.obj + estring2.obj + efixedstring.obj
 *
 * v2 (S18 post-KimiWorker-incident): added byte-match conversion guidance.
 * No method signature changes — the v1 declarations are canonical and
 * byte-match-correct (KimiWorker's MakeUpper fake-struct used wrong
 * return type, see postmortem info-post `postmortem` id a2da1ccb).
 *
 * ============================================================================
 * Use EString.h for ANY string-touching semantic conversion. The three
 * string classes cover:
 *   EString       — 8-bit ASCII/UTF-8 (single ptr m_buffer @ +0x00)
 *   EString2      — 16-bit wide (single ptr m_buffer @ +0x00, u16*)
 *   EFixedString  — 8-bit with fixed external buffer (ptr + maxLen)
 *
 * TArray<T, TArrayDefaultAllocator> is EA's dynamic array template (3-word
 * head: data, size, capacity). Explicit specializations for
 * TArray<EString*> + TArray<EString2*> are provided because their TU has
 * specific Construct/Copy/SetSize implementations.
 *
 * ============================================================================
 * **BYTE-MATCH CONVERSION GUIDANCE (READ BEFORE WRITING ANY EString CONVERT)**
 *
 * The KimiWorker EString incident (commits 7b81fa6a9 + fef98cc51 reverted
 * after floor breach) was caused by fake-struct deviation from this
 * canonical layout. To avoid repeating:
 *
 * 1. **#include "types/EString.h"** instead of declaring a local fake struct.
 *    Do NOT redeclare `struct EString_MU { char* m_buffer; ... }` or
 *    similar local-renamed shims. The fake struct generates DIFFERENT
 *    mangled symbols which can collide with the real EString in other
 *    TUs, causing collateral byte-match damage in unrelated units (the
 *    7b81fa6a9 incident broke a 152B person-unit function via this
 *    mechanism).
 *
 * 2. **Use the canonical method signatures EXACTLY as declared here.**
 *    Do NOT change return types (e.g. `void MakeUpper(void)` is canonical;
 *    `EString* MakeUpper(void)` would change the ABI). If a byte-match
 *    seems to require a different signature, post `typereq-amendment:
 *    EString_<method>_return_type` to the info board with the agent stub
 *    asm as evidence — TypeArch will amend within SLA.
 *
 * 3. **Use struct-member access patterns, NOT raw pointer arithmetic.**
 *    `m_buffer[i]` good; `((char*)this)[+0x00]` bad. The register-
 *    allocation drift insight from the BString2 incident: raw-cast access
 *    patterns reuse r3, struct-member access uses r9 intermediates.
 *    Compiler emits different code for byte-identical-looking source.
 *
 * 4. **Helper methods (Deallocate / SetToNull / FreeBuffer / AllocBuffer
 *    / MakeCopy) ARE real EString::* member methods** per symbol map
 *    (live in 0x8046xxxx range — possibly TU-duplicated; verify the bl
 *    target address via the FIXED awk one-liner before bl-calling them
 *    in your conversion). They are NOT private helpers or free functions.
 *
 * 5. **For in-place mutators (MakeUpper / MakeLower / Empty / Format /
 *    TrimLeft / TrimRight / Replace / etc.) declared `void` here:**
 *    `void` IS the byte-match-correct signature. Do not "upgrade" to
 *    `EString*` return — that's KimiWorker's MakeUpper mistake. The
 *    function preserves r3 in the original by being a leaf/clean-frame
 *    function, not by explicit return.
 *
 * If you suspect a canonical signature gap, POST a typereq don't fake-struct.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_ESTRING_H
#define SIMS2_TYPES_ESTRING_H

#include "../types.h"

/* Forward decls */
struct EStream;
struct __sFILE;

/* ============================================================================
 * TArrayDefaultAllocator — empty tag (no state) used to parameterize TArray
 * ========================================================================== */
struct TArrayDefaultAllocator {};

/* ============================================================================
 * TArray<T, Alloc> — EA's dynamic array template
 *
 * Head layout (3 words = 0x0C):
 *   0x00 T*  m_data
 *   0x04 s32 m_size
 *   0x08 s32 m_capacity
 * ========================================================================== */
template <class T, class Alloc>
class TArray {
public:
    /* 0x00 */ T*   m_data;
    /* 0x04 */ s32  m_size;
    /* 0x08 */ s32  m_capacity;

    void Init(void);
    void Add(T& item);
    void SetSize(s32 newSize, s32 newCap);
    void Insert(T* src, s32 pos, s32 count);
    void Destruct(T* ptr, s32 count);
    void Construct(T* ptr, s32 count);
    void Copy(T* dst, T* src, s32 count);
    void CopyReverse(T* dst, T* src, s32 count);
};

/* ============================================================================
 * EString — 8-bit string class wrapping a char* buffer
 *
 * Size: 0x04 (single ptr). EString instances are typically allocated
 * on the stack OR embedded as fields in larger objects. The buffer
 * itself lives in heap-allocated memory; m_null is a static singleton
 * for the empty-string case.
 * ========================================================================== */
class EString {
public:
    /* 0x00 */ char* m_buffer;

    static char m_null;       /* class-static empty-string sentinel */

    /* Ctors */
    EString(void);
    EString(char c);
    EString(char* start, char* end);

    /* Buffer mgmt */
    void  SetToNull(void);
    char* AllocBuffer(s32 size);
    void  Deallocate(char* buf);
    void  FreeBuffer(char* buf);
    void  MakeCopy(char* src);
    s32   Allocate(s32 size);

    /* Assignment */
    EString& operator=(char* str);

    /* Query / mutate */
    s32       GetLength(void) const;
    EString*  MakeUpper(void);  /* returns this; byte-match REQUIRES EString* return per KimiWorker A/B test 2026-05-24 (r3 preservation forces r11 intermediate for loop ptr) */
    void      MakeLower(void);  /* pending verify — may also need EString* return per symmetry */
    void      Empty(void);      /* void IS correct (has stack frame, reg-alloc determined by prologue) */

    /* Concat */
    EString  operator+(char c) const;
    EString& operator+=(char* str);
    EString& operator+=(char c);

    /* Compare */
    s32 Compare(char* str) const;
    s32 CompareNoCase(char* str) const;
    s32 CompareSymbol(char* str) const;

    /* Substr */
    EString Mid(s32 start, s32 count) const;
    EString Left(s32 count) const;
    EString Right(s32 count) const;

    /* Search */
    s32 Find(char c, s32 start) const;
    s32 FindNoCase(char c) const;
    s32 Find(char* str, s32 start) const;
    s32 FindNoCase(char* str) const;
    s32 FindReverse(char c) const;

    /* Replace */
    s32  Replace(char* from, char* to);
    void Replace(char oldChar, char newChar);
    void Remove(char c);

    /* Convert */
    void Convert(f32 val);
    void Convert(s32 val);
    void Convert(f64 val);

    /* Format */
    void Format(char* fmt, ...);

    /* Insert */
    void Insert(s32 pos, char c);
    void Insert(s32 pos, char* str);

    /* Buffer access */
    char* GetBuffer(s32 minLen);
    void  ReleaseBuffer(void);

    /* Path ops */
    void    FixTrailingSlash(void);
    void    RemoveTrailingSlash(void);
    void    RemoveDriveLetter(void);
    EString ExtractFilename(void) const;
    EString ExtractRoot(void) const;
    EString ExtractDirectory(void) const;
    EString ExtractExtension(void) const;
    void    MakeLegalFilename(void);
    void    MakeLegalSymbolName(void);
    void    RemoveRelationalDirectories(void);

    /* Trim */
    void TrimRight(char c);
    void TrimLeft(char c);
    void Trim(char c);
    void TrimRight(char* chars);
    void TrimLeft(char* chars);
    void Trim(char* chars);

    /* Slash conversion */
    void        ConvertToBackslashes(void);
    void        ConvertToForwardslashes(void);
    static void ConvertToBackslashes(char* str);
    static void ConvertToForwardslashes(char* str);

    /* Tokenize */
    void Tokenize(char* delimiters, TArray<EString, TArrayDefaultAllocator>& tokens);
    void GetLine(__sFILE* file);

    /* Helpers */
    static s32 CharsEqualNoCase(char a, char b);

    /* Cast */
    operator char*(void) const;
};

/* Free operators */
EString  operator+(char c, EString& str);
EStream& operator<<(EStream& stream, EString& str);
EStream& operator>>(EStream& stream, EString& str);

/* ============================================================================
 * EString2 — 16-bit wide string class (unsigned short / wchar_t)
 *
 * Size: 0x04 (single u16* m_buffer). UI text paths use EString2 throughout.
 * ========================================================================== */
class EString2 {
public:
    /* 0x00 */ u16* m_buffer;

    /* Ctors */
    EString2(wchar_t c);
    EString2(char c);
    EString2(u16* start, u16* end);

    /* Static */
    static s32 StrLenC16(u16* str);

    /* Buffer mgmt */
    void  SetToNull(void);
    void  SetToError(void);
    void  MakeCopy(u16* src);
    void  MakeCopyFromChars(char* src);
    void  Deallocate(u16* buf);
    s32   Allocate(s32 size, bool flag);

    /* Assignment */
    EString2& operator=(u16* str);
    EString2& operator=(char* str);
    EString2& operator=(wchar_t c);
    EString2& operator=(char c);

    /* Query / mutate */
    s32 GetLength(void) const;
    void MakeUpper(void);
    void MakeLower(void);
    void Empty(void);

    /* Compare */
    s32     Compare(u16* str) const;
    s32     Compare(char* str) const;
    s32     CompareNoCase(u16* str) const;
    EString GetEString(void) const;

    /* Substr */
    EString2 Mid(s32 start, s32 count) const;
    EString2 Left(s32 count) const;
    EString2 Right(s32 count) const;

    /* Concat */
    EString2& operator+=(u16* str);
    EString2  operator+(wchar_t c);
    EString2& operator+=(wchar_t c);
    EString2  operator+(char* str) const;
    EString2  operator+(EString& str) const;
    EString2  operator+(char c) const;
    EString2& operator+=(EString& str);
    EString2& operator+=(char* str);
    EString2& operator+=(char c);

    /* Search */
    s32 Find(wchar_t c) const;
    s32 Find(u16* str) const;
    s32 FindReverse(wchar_t c) const;

    /* Replace */
    void Replace(u16* from, u16* to);
    void Replace(wchar_t oldChar, wchar_t newChar);
    void Remove(wchar_t c);
    void RemoveTrailing(wchar_t c);

    /* Convert */
    void Convert(f32 val);
    void Convert(s32 val);
    void Convert(f64 val);

    /* Tokenize */
    void     Tokenize(wchar_t delim, TArray<EString2, TArrayDefaultAllocator>& tokens);
    EString2 GetNextToken(s32& pos, s32 len, wchar_t delim);
    void     GetLine(__sFILE* file);

    /* Path ops */
    void     FixTrailingSlash(void);
    void     RemoveTrailingSlash(void);
    EString2 ExtractFilename(void) const;
    EString2 ExtractRoot(void) const;
    EString2 ExtractDirectory(void) const;
    EString2 ExtractExtension(void) const;
    void     MakeLegalFilename(void);

    /* Slash conversion */
    void ConvertToBackslashes(void);
    void ConvertToForwardslashes(void);

    /* Cast */
    operator u16*(void) const;
};

/* Free operators */
EString2 operator+(wchar_t c, EString2& str);
EStream& operator<<(EStream& stream, EString2& str);
EStream& operator>>(EStream& stream, EString2& str);

/* ============================================================================
 * TArray explicit specializations for EString / EString2
 *
 * These exist because the string-TU's Construct/Copy/SetSize implementations
 * are TU-local and not template-generated from the primary TArray<T> body.
 * ========================================================================== */
template <>
class TArray<EString, TArrayDefaultAllocator> {
public:
    /* 0x00 */ EString* m_data;
    /* 0x04 */ s32      m_size;
    /* 0x08 */ s32      m_capacity;

    void Construct(EString* dst, s32 count);
    void Copy(EString* dst, EString* src, s32 count);
    void SetSize(s32 newSize, s32 growBy);
    void CopyReverse(EString* dst, EString* src, s32 count);
    void Insert(EString* item, s32 index, s32 count);
    void Add(EString& item);
};

template <>
class TArray<EString2, TArrayDefaultAllocator> {
public:
    /* 0x00 */ EString2* m_data;
    /* 0x04 */ s32       m_size;
    /* 0x08 */ s32       m_capacity;

    void Destruct(EString2* ptr, s32 count);
    void Init(void);
    void Construct(EString2* dst, s32 count);
    void Copy(EString2* dst, EString2* src, s32 count);
    void SetSize(s32 newSize, s32 growBy);
    void CopyReverse(EString2* dst, EString2* src, s32 count);
    void Insert(EString2* item, s32 index, s32 count);
    void Add(EString2& item);
};

/* ============================================================================
 * EFixedString — string with an externally-supplied fixed-size buffer
 *
 * Size: 0x08 (char* + maxLen). Doesn't allocate; buffer is supplied by
 * caller. Used for stack-local string builders + APT/UI fixed-buffer
 * intermediates.
 * ========================================================================== */
class EFixedString {
public:
    /* 0x00 */ char* m_buffer;
    /* 0x04 */ s32   m_maxLen;

    void Init(void* buf, s32 maxLen);

    /* Concat */
    void Concatonate(char* a, char* b);
    void Concatonate(char* a, char  b);
    void Concatonate(char  a, char* b);

    /* Copy */
    void MakeCopy(char* src);
    void MakeCopy(char  c);

    /* Query / mutate */
    s32 GetLength(void) const;
    void MakeUpper(void);
    void MakeLower(void);

    /* Compare */
    s32 Compare(char* str) const;
    s32 CompareNoCase(char* str) const;
    s32 CompareSymbol(char* str) const;

    /* Substr (write into out parameter) */
    void Mid(EFixedString& out, s32 start, s32 count) const;
    void Left(EFixedString& out, s32 count) const;
    void Right(EFixedString& out, s32 count) const;

    /* Concat ops */
    EFixedString& operator+=(char* str);
    EFixedString& operator+=(char  c);

    /* Search */
    s32 Find(char c) const;
    s32 FindNoCase(char c) const;
    s32 Find(char* str) const;
    s32 FindNoCase(char* str) const;
    s32 FindReverse(char c) const;

    /* Replace */
    void Replace(EFixedString& out, char* from, char* to);
    void Replace(char oldChar, char newChar);
    void Remove(EFixedString& out, char c);

    /* Convert */
    void Convert(f32 val);
    void Convert(s32 val);
    void Convert(f64 val);

    /* Path ops */
    void FixTrailingSlash(void);
    void RemoveTrailingSlash(void);
    void RemoveDriveLetter(void);
    void ExtractFilename(EFixedString& out) const;
    void ExtractRoot(EFixedString& out) const;
    void ExtractDirectory(EFixedString& out) const;
    void ExtractExtension(EFixedString& out) const;
    void MakeLegalFilename(void);

    /* Trim */
    void TrimRight(char c);
    void TrimLeft(char c);
    void Trim(char c);
    void TrimRight(char* chars);
    void TrimLeft(char* chars);
    void Trim(char* chars);

    /* Buffer access */
    char* GetBuffer(s32 minLen);
    void  ReleaseBuffer(void);

    /* Helpers */
    static s32 CharsEqualNoCase(char a, char b);
};

/* Free operators */
EStream& operator<<(EStream& stream, EFixedString& str);
EStream& operator>>(EStream& stream, EFixedString& str);

#endif /* SIMS2_TYPES_ESTRING_H */
