// e_string.cpp - EString, EString2, EFixedString functions
// From: base_ngc_release_dvd.lib(e_string.obj, e_string2.obj, e_fixedstring.obj)
// Small functions (<=64 bytes) decompiled from these objects

#include "core/e_string.h"

// External function declarations
extern "C" int strlen(const char* s);
extern "C" char* strlwr(char* s);

// External class functions
class EAHeap;
class EPathUtil;

extern EAHeap* MainHeap(void);

namespace {
    // EAHeap functions we call through MainHeap()
    extern "C" void* EAHeap_Malloc(EAHeap* heap, unsigned int size, int align);
    extern "C" void EAHeap_Free(EAHeap* heap, void* ptr);
}

// Forward declarations for path utilities
extern void EPathUtil_MakeLegalFilename(char* dst, char* src);
extern void EPathUtil_FixTrailingSlash(char* dst, char* src);
extern void EPathUtil_RemoveTrailingSlash(char* dst, char* src);
extern void EPathUtil_RemoveDriveLetter(char* dst, char* src);
extern void EStream_WriteU16String(EStream& stream, unsigned short* str);

// ============================================================================
// EString small functions from e_string.obj
// ============================================================================

// EString::SetToNull - 0x802d293c (12 bytes)
// NON_MATCHING - SDA (r13) addressing vs absolute for m_null
// Sets buffer to point to the static null character
void EString::SetToNull(void) {
    m_buffer = &m_null;
}

// EString::Deallocate - 0x802d2948 (44 bytes)
// NON_MATCHING - SDA (r13) vs absolute addressing for m_null comparison
// Frees a buffer if it's not the null sentinel
void EString::Deallocate(char* buf) {
    if (buf != &m_null) {
        FreeBuffer(buf);
    }
}

// EString::EString(char) - 0x802d2844 (60 bytes)
// NON_MATCHING - Constructs from a single character
// Original: slwi r4,r4,8; sth r4,8(r1); calls MakeCopy with stack buffer
// The shift-left-8 + sth stores char in high byte with null terminator
EString::EString(char c) {
    char tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    MakeCopy(tmp);
}

// EString::AllocBuffer - 0x802d2974 (52 bytes)
// NON_MATCHING - Allocates a buffer through MainHeap
// Original saves r4 (size) in r30, calls MainHeap(), then Malloc(result, r30, 0)
// Return value stored in this->m_buffer done differently
void EString::AllocBuffer(int size) {
    EAHeap* heap = MainHeap();
    m_buffer = (char*)EAHeap_Malloc(heap, size, 0);
}

// EString::FreeBuffer - 0x802d29ac (52 bytes)
// Frees a buffer through MainHeap
void EString::FreeBuffer(char* buf) {
    EAHeap* heap = MainHeap();
    EAHeap_Free(heap, buf);
}

// EString::operator=(char*) - 0x802d2be4 (64 bytes)
// Assignment from char*: copies new, then deallocates old
EString& EString::operator=(char* str) {
    char* old = m_buffer;
    MakeCopy(str);
    Deallocate(old);
    return *this;
}

// EString::GetLength - 0x802d2c24 (36 bytes)
// Returns strlen of the buffer
int EString::GetLength(void) const {
    return strlen(m_buffer);
}

// EString::MakeUpper - 0x802d2c48 (52 bytes)
// NON_MATCHING - register allocation differs (cmpwi vs andi.)
// Converts string to uppercase in-place (no libc, manual loop)
void EString::MakeUpper(void) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if ((unsigned int)(c - 'a') <= 25) {
            *p = c - 32;
        }
        c = *++p;
    } while (c != 0);
}

// EString::MakeLower - 0x802d2c7c (52 bytes)
// Converts string to lowercase using strlwr
void EString::MakeLower(void) {
    strlwr(m_buffer);
}

// EString::Empty - 0x802d2d40 (56 bytes)
// NON_MATCHING - inlining differences (Deallocate/SetToNull inlined differently)
// Deallocates buffer and sets to null
void EString::Empty(void) {
    Deallocate(m_buffer);
    SetToNull();
}

// EString::operator+(char) const - 0x802d3100 (64 bytes)
// NON_MATCHING - returns EString constructed from (this->m_buffer, char)
// Concatenation: appends a single character
EString EString::operator+(char c) const {
    // This is a return-by-value function where r3 = hidden return ptr
    // It constructs the result from m_buffer and the char appended
    char tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    // Construct result using EString(char*, char*) - start=m_buffer, end=tmp
    EString result(m_buffer, tmp);
    return result;
}

// EString::Replace(char, char) - 0x802d3534 (48 bytes)
// NON_MATCHING - original uses extsb for sign extension, comparison order differs
// Replaces all occurrences of one character with another
void EString::Replace(char oldChar, char newChar) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if ((char)c == oldChar) {
            *p = newChar;
        }
        c = *++p;
    } while (c != 0);
}

// operator+(char, EString&) - 0x802d3610 (64 bytes)
// NON_MATCHING - free function: constructs string from char + string
// Prepends char to string
EString operator+(char c, EString& str) {
    char tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    EString result(tmp, str.m_buffer);
    return result;
}

// EString::FixTrailingSlash - 0x802d36f4 (64 bytes)
// NON_MATCHING - calls EPathUtil::FixTrailingSlash into stack buffer, then assigns
void EString::FixTrailingSlash(void) {
    char buf[264];
    EPathUtil_FixTrailingSlash(buf, m_buffer);
    *this = buf;
}

// EString::RemoveTrailingSlash - 0x802d3734 (64 bytes)
// NON_MATCHING - calls EPathUtil::RemoveTrailingSlash into stack buffer, then assigns
void EString::RemoveTrailingSlash(void) {
    char buf[264];
    EPathUtil_RemoveTrailingSlash(buf, m_buffer);
    *this = buf;
}

// EString::RemoveDriveLetter - 0x802d3774 (40 bytes)
// Calls EPathUtil::RemoveDriveLetter in-place
void EString::RemoveDriveLetter(void) {
    EPathUtil_RemoveDriveLetter(m_buffer, m_buffer);
}

// EString::MakeLegalFilename - 0x802d38ac (56 bytes)
// Calls EPathUtil::MakeLegalFilename in-place
void EString::MakeLegalFilename(void) {
    EPathUtil_MakeLegalFilename(m_buffer, m_buffer);
}

// EString::Trim(char) - 0x802d3aa0 (64 bytes)
// Trims from both sides
void EString::Trim(char c) {
    TrimLeft(c);
    TrimRight(c);
}

// EString::Trim(char*) - 0x802d3c08 (64 bytes)
// Trims from both sides
void EString::Trim(char* chars) {
    TrimLeft(chars);
    TrimRight(chars);
}

// EString::GetBuffer - 0x802d3e78 (60 bytes)
// Returns writable buffer pointer if Allocate succeeds
char* EString::GetBuffer(int minLen) {
    int result = Allocate(minLen);
    if (result == 0) {
        return 0;
    }
    return m_buffer;
}

// EString::ReleaseBuffer - 0x802d3eb4 (36 bytes)
// Reassigns from current buffer (updates internal state)
void EString::ReleaseBuffer(void) {
    *this = m_buffer;
}

// EString::Convert(double) - 0x802d3ed8 (36 bytes)
// Converts double to float and calls Convert(float)
void EString::Convert(double val) {
    Convert((float)val);
}

// EString::ConvertToBackslashes(void) - 0x802d3f78 (48 bytes)
// Replaces '/' with '\' in buffer
void EString::ConvertToBackslashes(void) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if (c == '/') {
            *p = '\\';
        }
        c = *++p;
    } while (c != 0);
}

// EString::ConvertToForwardslashes(void) - 0x802d3fa8 (48 bytes)
// Replaces '\' with '/' in buffer
void EString::ConvertToForwardslashes(void) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if (c == '\\') {
            *p = '/';
        }
        c = *++p;
    } while (c != 0);
}

// EString::ConvertToBackslashes(char*) - 0x802d3fd8 (44 bytes)
// Static: replaces '/' with '\' in a raw char*
void EString::ConvertToBackslashes(char* str) {
    char c = *str;
    if (c == 0) return;
    do {
        if (c == '/') {
            *str = '\\';
        }
        c = *++str;
    } while (c != 0);
}

// EString::ConvertToForwardslashes(char*) - 0x802d4004 (44 bytes)
// Static: replaces '\' with '/' in a raw char*
void EString::ConvertToForwardslashes(char* str) {
    char c = *str;
    if (c == 0) return;
    do {
        if (c == '\\') {
            *str = '/';
        }
        c = *++str;
    } while (c != 0);
}

// TArray<EString>::Add - 0x803c2b50 (40 bytes)
// Inserts item at end of array
void TArray<EString, TArrayDefaultAllocator>::Add(EString& item) {
    Insert(&item, m_size, 1);
}

// ============================================================================
// EString2 small functions from e_string2.obj
// ============================================================================

// Extern: wide null and error strings (SDA-relative)
extern unsigned short _estring2Null[2];   // at r13 - 26852
extern unsigned short _estring2Error[8];  // at 0x8043ed54

// EString2::SetToNull - 0x802d418c (12 bytes)
// Sets buffer to static null wide string
void EString2::SetToNull(void) {
    m_buffer = _estring2Null;
}

// EString2::SetToError - 0x802d4198 (16 bytes)
// Sets buffer to static error wide string "<error>"
void EString2::SetToError(void) {
    m_buffer = _estring2Error;
}

// EString2::StrLenC16 - 0x802d4154 (56 bytes)
// Returns length of unsigned short string (wcslen equivalent)
int EString2::StrLenC16(unsigned short* str) {
    if (!str) return 0;
    int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

// EString2::EString2(wchar_t) - 0x802d4030 (64 bytes)
// Constructs from a single wide character
EString2::EString2(wchar_t c) {
    unsigned short tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    MakeCopy(tmp);
}

// EString2::EString2(char) - 0x802d4460 (64 bytes)
// Constructs from a single ASCII character (stored as wide)
EString2::EString2(char c) {
    unsigned short tmp[2];
    tmp[0] = (unsigned short)c;
    tmp[1] = 0;
    MakeCopy(tmp);
}

// EString2::Convert(double) - 0x802d4130 (36 bytes)
// Converts double to float and calls Convert(float)
void EString2::Convert(double val) {
    Convert((float)val);
}

// EString2::operator=(unsigned wchar_t*) - 0x802d4658 (64 bytes)
// Assignment from unsigned wchar_t*
EString2& EString2::operator=(unsigned short* str) {
    unsigned short* old = m_buffer;
    MakeCopy(str);
    Deallocate(old);
    return *this;
}

// EString2::operator=(char*) - 0x802d4698 (64 bytes)
// Assignment from char* (converts to wide)
EString2& EString2::operator=(char* str) {
    unsigned short* old = m_buffer;
    MakeCopyFromChars(str);
    Deallocate(old);
    return *this;
}

// EString2::GetLength - 0x802d4780 (36 bytes)
// Returns StrLenC16 of the buffer
int EString2::GetLength(void) const {
    return StrLenC16(m_buffer);
}

// EString2::MakeUpper - 0x802d47a4 (56 bytes)
// Converts wide string to uppercase in-place
// NON_MATCHING - the addis r9,r9,1 might not match
void EString2::MakeUpper(void) {
    unsigned short* p = m_buffer;
    unsigned short c = *p;
    if (c == 0) return;
    do {
        if ((unsigned int)(c - 'a') <= 25) {
            *p = c - 32;
        }
        c = *++p;
    } while (c != 0);
}

// EString2::MakeLower - 0x802d47dc (52 bytes)
// Converts wide string to lowercase in-place
void EString2::MakeLower(void) {
    unsigned short* p = m_buffer;
    unsigned short c = *p;
    if (c == 0) return;
    do {
        if ((unsigned int)(c - 'A') <= 25) {
            *p = c + 32;
        }
        c = *++p;
    } while (c != 0);
}

// EString2::Empty - 0x802d48d0 (56 bytes)
// Deallocates buffer and sets to null
void EString2::Empty(void) {
    Deallocate(m_buffer);
    SetToNull();
}

// EString2::Find(wchar_t) - 0x802d4f08 (60 bytes)
// Finds first occurrence of wide char, returns index or -1
int EString2::Find(wchar_t c) const {
    unsigned short* p = m_buffer;
    int i = 0;
    unsigned short ch = *p;
    if (ch == 0) {
        return -1;
    }
    do {
        if (ch == (unsigned short)c) {
            return i;
        }
        ch = *++p;
        i++;
    } while (ch != 0);
    return -1;
}

// EString2::Replace(wchar_t, wchar_t) - 0x802d51c8 (44 bytes)
// Replaces all occurrences of one wide char with another
void EString2::Replace(wchar_t oldChar, wchar_t newChar) {
    unsigned short* p = m_buffer;
    unsigned short c = *p;
    if (c == 0) return;
    do {
        if (c == (unsigned short)oldChar) {
            *p = (unsigned short)newChar;
        }
        c = *++p;
    } while (c != 0);
}

// operator<<(EStream&, EString2&) - 0x802d5378 (52 bytes)
// Writes wide string to stream
EStream& operator<<(EStream& stream, EString2& str) {
    EStream_WriteU16String(stream, str.m_buffer);
    return stream;
}

// EString2::ConvertToBackslashes(void) - 0x802d57f0 (48 bytes)
// Replaces '/' with '\' in wide buffer
void EString2::ConvertToBackslashes(void) {
    unsigned short* p = m_buffer;
    unsigned short c = *p;
    if (c == 0) return;
    do {
        if (c == '/') {
            *p = '\\';
        }
        c = *++p;
    } while (c != 0);
}

// EString2::ConvertToForwardslashes(void) - 0x802d5820 (48 bytes)
// Replaces '\' with '/' in wide buffer
void EString2::ConvertToForwardslashes(void) {
    unsigned short* p = m_buffer;
    unsigned short c = *p;
    if (c == 0) return;
    do {
        if (c == '\\') {
            *p = '/';
        }
        c = *++p;
    } while (c != 0);
}

// TArray<EString2>::Init - 0x803c2bc8 (20 bytes)
// Initializes array to empty state
void TArray<EString2, TArrayDefaultAllocator>::Init(void) {
    m_size = 0;
    m_data = 0;
    m_capacity = 0;
}

// TArray<EString2>::Add - 0x803c2ee8 (40 bytes)
// Inserts item at end of array
void TArray<EString2, TArrayDefaultAllocator>::Add(EString2& item) {
    Insert(&item, m_size, 1);
}

// EString2::operator unsigned wchar_t* - 0x803c2f10 (8 bytes)
// Cast operator: returns buffer pointer
EString2::operator unsigned short*(void) const {
    return m_buffer;
}

// ============================================================================
// EFixedString small functions from e_fixedstring.obj
// ============================================================================

// Extern: static null for fixed strings
extern char _fixedStringNull[4]; // at SDA

// EFixedString::Init - 0x802c7414 (20 bytes)
// Initializes fixed string with buffer and max length
void EFixedString::Init(void* buf, int maxLen) {
    m_maxLen = maxLen;
    m_buffer = (char*)buf;
    *(char*)buf = 0;
}

// EFixedString::Concatonate(char*, char) - 0x802c7500 (44 bytes)
// Concatenates a string and a single char
void EFixedString::Concatonate(char* a, char b) {
    char tmp[2];
    tmp[0] = b;
    tmp[1] = 0;
    Concatonate(a, tmp);
}

// EFixedString::Concatonate(char, char*) - 0x802c752c (44 bytes)
// Concatenates a single char and a string
void EFixedString::Concatonate(char a, char* b) {
    char tmp[2];
    tmp[0] = a;
    tmp[1] = 0;
    Concatonate(tmp, b);
}

// EFixedString::MakeCopy(char) - 0x802c75e8 (28 bytes)
// Copies a single character into the buffer
void EFixedString::MakeCopy(char c) {
    m_buffer[0] = c;
    m_buffer[1] = 0;
}

// EFixedString::GetLength - 0x802c7604 (36 bytes)
// Returns strlen of the buffer
int EFixedString::GetLength(void) const {
    return strlen(m_buffer);
}

// EFixedString::MakeUpper - 0x802c7628 (52 bytes)
// Converts to uppercase in-place
void EFixedString::MakeUpper(void) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if ((unsigned int)(c - 'a') <= 25) {
            *p = c - 32;
        }
        c = *++p;
    } while (c != 0);
}

// EFixedString::MakeLower - 0x802c765c (52 bytes)
// Converts to lowercase in-place
void EFixedString::MakeLower(void) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if ((unsigned int)(c - 'A') <= 25) {
            *p = c + 32;
        }
        c = *++p;
    } while (c != 0);
}

// EFixedString::operator+=(char) - 0x802c7a18 (60 bytes)
// Appends a single character
EFixedString& EFixedString::operator+=(char c) {
    char tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    *this += tmp;
    return *this;
}

// EFixedString::Find(char) - 0x802c7a54 (64 bytes)
// Finds first occurrence of character, returns index or -1
int EFixedString::Find(char c) const {
    char* p = m_buffer;
    int i = 0;
    char ch = *p;
    if (ch == 0) {
        return -1;
    }
    do {
        if ((char)ch == c) {
            return i;
        }
        ch = *++p;
        i++;
    } while (ch != 0);
    return -1;
}

// EFixedString::Replace(char, char) - 0x802c7e04 (48 bytes)
// Replaces all occurrences of one character with another
void EFixedString::Replace(char oldChar, char newChar) {
    char* p = m_buffer;
    char c = *p;
    if (c == 0) return;
    do {
        if ((char)c == oldChar) {
            *p = newChar;
        }
        c = *++p;
    } while (c != 0);
}

// EFixedString::Trim(char) - 0x802c8478 (64 bytes)
// Trims from both sides
void EFixedString::Trim(char c) {
    TrimLeft(c);
    TrimRight(c);
}

// EFixedString::Trim(char*) - 0x802c85d0 (64 bytes)
// Trims from both sides
void EFixedString::Trim(char* chars) {
    TrimLeft(chars);
    TrimRight(chars);
}

// EFixedString::GetBuffer - 0x802c8610 (28 bytes)
// Returns buffer if minLen fits, else NULL
char* EFixedString::GetBuffer(int minLen) {
    if (minLen > m_maxLen) {
        return 0;
    }
    return m_buffer;
}

// EFixedString::ReleaseBuffer - 0x802c862c (4 bytes)
// No-op for fixed strings (no allocation)
void EFixedString::ReleaseBuffer(void) {
}

// EFixedString::Convert(double) - 0x802c8630 (36 bytes)
// Converts double to float and calls Convert(float)
void EFixedString::Convert(double val) {
    Convert((float)val);
}
