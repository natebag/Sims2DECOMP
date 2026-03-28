// stringbuffer.cpp - StringBuffer small functions
// From: stringbuffer.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/stringbuffer.h"

// ============================================================================
// External references
// ============================================================================
extern "C" unsigned int strlen(const char* str);

// ============================================================================
// localConvertToASCII(char *, unsigned wchar_t *)
// 0x800a657c - 48 bytes
// Converts a wide (16-bit) string to ASCII by taking the low byte of each char.
// Note: identical copy also exists in ctgdump.obj (0x800a5128).
// ============================================================================
static void localConvertToASCII(char* dst, unsigned short* src) {
    while (*src != 0) {
        *dst = (char)*src;  // takes low byte
        dst++;
        src++;
    }
    *dst = 0;
}

// ============================================================================
// StringBuffer::StringBuffer(char *, unsigned int)
// 0x800a65ac - 56 bytes
// Constructor: stores buffer pointer and capacity, then erases
// ============================================================================
// NON_MATCHING - GCC inlines erase() into the constructor at -O2.
// Original makes a bl to erase() as a separate call.
// Original uses stmw r30 / lmw r30 to save r30 for 'this' pointer.
StringBuffer::StringBuffer(char* buffer, unsigned int capacity) {
    m_buffer = buffer;
    m_capacity = capacity;
    erase();
}

// ============================================================================
// StringBuffer::capacity(void) const
// 0x800a65e4 - 8 bytes
// lwz r3, 4(r3); blr
// ============================================================================
unsigned int StringBuffer::capacity(void) const {
    return m_capacity;
}

// ============================================================================
// StringBuffer::length(void) const
// 0x800a65ec - 36 bytes
// Loads m_buffer then calls strlen
// ============================================================================
unsigned int StringBuffer::length(void) const {
    return strlen(m_buffer);
}

// ============================================================================
// StringBuffer::erase(void)
// 0x800a6610 - 16 bytes
// lwz r9, 0(r3); li r0, 0; stb r0, 0(r9); blr
// ============================================================================
void StringBuffer::erase(void) {
    m_buffer[0] = 0;
}

// ============================================================================
// StringBuffer::c_str(void) const
// 0x800a6718 - 8 bytes
// lwz r3, 0(r3); blr
// ============================================================================
const char* StringBuffer::c_str(void) const {
    return m_buffer;
}

// ============================================================================
// StringBuffer::buffer(void)
// 0x800a6720 - 8 bytes
// lwz r3, 0(r3); blr
// ============================================================================
char* StringBuffer::buffer(void) {
    return m_buffer;
}

// ============================================================================
// StringBuffer::copy(char *)
// 0x800a6728 - 64 bytes
// Erases buffer, then appends the source string
// ============================================================================
// NON_MATCHING - GCC inlines erase() at -O2 and uses tail call for append.
// Original saves r29/r30 (stmw r29), calls erase() via bl, then calls append() via bl.
void StringBuffer::copy(char* src) {
    erase();
    append(src, -1);
}

// ============================================================================
// StringBuffer::copy(StringBuffer &)
// 0x800a6768 - 64 bytes
// Erases buffer, then appends from another StringBuffer
// ============================================================================
// NON_MATCHING - Same inlining issue as copy(char*).
void StringBuffer::copy(StringBuffer& src) {
    erase();
    append(src, -1);
}

// ============================================================================
// StringBuffer::appendChar(char)
// 0x800a69e4 - 48 bytes
// Appends a single character by converting to wchar on stack and calling append
// ============================================================================
// NON_MATCHING - Frame size differs (original 16 vs GCC 24).
// Original: slwi r4,r4,8 directly, stores to stack at sp+8 as half-word.
// GCC: uses r9 for shift result and different frame layout.
void StringBuffer::appendChar(char c) {
    unsigned short wc = ((unsigned char)c) << 8;
    append((char*)&wc, -1);
}
