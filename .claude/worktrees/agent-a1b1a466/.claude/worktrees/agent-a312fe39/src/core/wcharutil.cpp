// wcharutil.cpp - Wide character utility functions
// From: wcharutil.obj
// Small functions (<=64 bytes) decompiled from this object
// Note: wchar_t is 16-bit on GameCube (-fshort-wchar), stored as unsigned short
//
// NON_MATCHING - All 5 functions differ in register allocation and loop structure
// between GCC and SN Systems compilers. Structurally equivalent.

#include "core/wcharutil.h"

// ============================================================================
// wcslen
// 0x800A7E78 - 40 bytes
// Returns length of wide string (not counting null terminator)
// ============================================================================
// lhz r0,0(r3); li r9,0; cmpwi r0,0; beq- done
// lhzu r0,2(r3); addi r9,r9,1; cmpwi r0,0; bne+ loop
// done: mr r3,r9; blr
// NON_MATCHING - GCC unrolls loop and uses different registers
int wcslen(const wchar_t* str) {
    int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

// ============================================================================
// wcscmp
// 0x800A7EA0 - 48 bytes
// Compares two wide strings, returns difference of first mismatched chars
// ============================================================================
// loop: lhz r0,0(r3); lhz r9,0(r4); subf. r11,r9,r0; bne- done
// cmpwi r0,0; addi r3,r3,2; beq- done
// cmpwi r9,0; addi r4,r4,2; bne+ loop
// done: mr r3,r11; blr
// NON_MATCHING - GCC uses different register allocation and branch structure
int wcscmp(const wchar_t* s1, const wchar_t* s2) {
    int diff;
    for (;;) {
        unsigned short c1 = *(const unsigned short*)s1;
        unsigned short c2 = *(const unsigned short*)s2;
        diff = c1 - c2;
        if (diff != 0) break;
        if (c1 == 0) break;
        s1++;
        if (c2 == 0) break;
        s2++;
    }
    return diff;
}

// ============================================================================
// wcscpy
// 0x800A7ED0 - 48 bytes
// Copies wide string src to dst, returns dst
// ============================================================================
// lhz r0,0(r4); mr r9,r3; cmpwi r0,0; beq- done
// loop: sth r0,0(r9); lhzu r0,2(r4); addi r9,r9,2; cmpwi r0,0; bne+ loop
// done: li r0,0; sth r0,0(r9); blr
// NON_MATCHING - GCC adds clrlwi instructions and different loop structure
wchar_t* wcscpy(wchar_t* dst, const wchar_t* src) {
    wchar_t* ret = dst;
    unsigned short c = *(const unsigned short*)src;
    if (c != 0) {
        do {
            *(unsigned short*)dst = c;
            src++;
            c = *(const unsigned short*)src;
            dst++;
        } while (c != 0);
    }
    *(unsigned short*)dst = 0;
    return ret;
}

// ============================================================================
// wcsncmp
// 0x800A7F5C - 64 bytes
// Compares at most n chars of two wide strings
// ============================================================================
// li r11,0
// loop: lhz r0,0(r3); addi r11,r11,1; lhz r9,0(r4)
// subf. r10,r9,r0; bne- done
// cmpwi r0,0; addi r3,r3,2; beq- done
// cmpwi r9,0; addi r4,r4,2; beq- done
// cmpw r11,r5; blt+ loop
// done: mr r3,r10; blr
// NON_MATCHING - GCC converts to CTR-based loop with bdnz
int wcsncmp(const wchar_t* s1, const wchar_t* s2, int n) {
    int i = 0;
    int diff;
    for (;;) {
        unsigned short c1 = *(const unsigned short*)s1;
        i++;
        unsigned short c2 = *(const unsigned short*)s2;
        diff = c1 - c2;
        if (diff != 0) break;
        if (c1 == 0) break;
        s1++;
        if (c2 == 0) break;
        s2++;
        if (i >= n) break;
    }
    return diff;
}

// ============================================================================
// wcschr
// 0x800A7F9C - 56 bytes
// Finds first occurrence of character c in wide string, or NULL if not found
// ============================================================================
// lhz r0,0(r3); b check
// loop: lhzu r0,2(r3)
// check: cmpwi r0,0; beq- found_end; cmpw r0,r4; bne+ loop
// found_end: lhz r0,0(r3); li r9,0; cmpwi r0,0; beq- null
// mr r9,r3
// null: mr r3,r9; blr
// NON_MATCHING - GCC generates different null-check pattern
wchar_t* wcschr(const wchar_t* str, wchar_t c) {
    unsigned short ch = *(const unsigned short*)str;
    while (ch != 0 && ch != (unsigned short)c) {
        str++;
        ch = *(const unsigned short*)str;
    }
    if (*(const unsigned short*)str == 0) {
        return 0;
    }
    return (wchar_t*)str;
}
