// EAString.cpp - EA's simple string class implementation
// Source: libaptz.a(EAString.cpp.obj)
// 7 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_value.h"
#include "ui/apt_ea_string.h"

// External functions
extern void EAStringC_ChangeBuffer(EAStringC* str, unsigned int a, unsigned int b,
                                    unsigned int c, int pushZero, unsigned int d);
extern void EAStringC_TrimLeft(EAStringC* str, char* chars);
extern void EAStringC_TrimRight(EAStringC* str, char* chars);

// ============================================================================
// EAStringC::ReserveSize (0x802bc858, 64 bytes) NON_MATCHING
// Original:
//   lwz r9,0(r3)           ; load m_pData
//   lhz r6,2(r9)           ; load m_pData->m_bufferSize (offset 0x02)
//   cmplw r6,r4             ; compare bufferSize vs requested size
//   ble skip                ; if buffer >= requested, use requested
//   mr r6,r4                ; else use current size as preserve amount
// skip:
//   li r5,0 / li r7,1      ; args: offset=0, pushZero=CB_PUSH_ZERO
//   mr r8,r6                ; preserveSize
//   bl EAStringC::ChangeBuffer(newSize, offset, 0, pushZero, preserveSize)
//   epilogue
//
// Ensures buffer has at least 'size' capacity, preserving existing content.
// ============================================================================
void EAStringC_ReserveSize(EAStringC* str, unsigned int size) {
    EAStringCInternalData* data = str->m_pData;
    unsigned int preserveSize = data->m_pad;  // m_bufferSize at offset 0x02
    if (preserveSize > size) {
        preserveSize = size;
    }
    EAStringC_ChangeBuffer(str, size, 0, 0, 1, preserveSize);
}

// ============================================================================
// EAStringC::IsEnoughSize (0x802bc898, 24 bytes) NON_MATCHING
// Original:
//   lwz r9,0(r3)           ; load m_pData
//   lhz r3,4(r9)           ; load m_pData->m_length (offset 0x04)
//   subfc r3,r3,r4         ; r3 = r4 - r3 (sets carry if r4 >= r3)
//   subfe r3,r3,r3         ; r3 = carry ? 0 : -1
//   neg r3,r3              ; r3 = carry ? 0 : 1
//   blr
// Returns true (1) if the current length is greater than the requested size.
// Actually: returns (size >= length) ? 0 : 1, i.e. returns 1 if NOT enough size.
// Wait - subfc sets carry if NO borrow, i.e. if r4 >= r3.
// subfe r3,r3,r3 = r3 - r3 - (1-carry) = -(1-carry) = carry-1
// So if r4 >= r3 (enough): carry=1, subfe=-0=0, neg=0 => returns 0
// If r4 < r3 (not enough): carry=0, subfe=-1, neg=1 => returns 1
// So it returns 1 if NOT enough size. But name is "IsEnoughSize"...
// The logic is inverted from what you'd expect from the name.
// ============================================================================
int EAStringC_IsEnoughSize(EAStringC* str, unsigned int size) {
    EAStringCInternalData* data = str->m_pData;
    u16 length = data->m_length;
    return (size < length) ? 1 : 0;
}

// ============================================================================
// EAStringC::FindOneOf (0x802bcc90, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Stub - always returns 0 (not found / not implemented)
// ============================================================================
int EAStringC_FindOneOf(EAStringC* str, char* chars) {
    return 0;
}

// ============================================================================
// EAStringC::ReverseFind (0x802bcc98, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Stub - always returns 0 (not found / not implemented)
// ============================================================================
int EAStringC_ReverseFind(EAStringC* str, char ch) {
    return 0;
}

// ============================================================================
// EAStringC::Insert(int, char*) (0x802bce38, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Stub - always returns 0 (not implemented)
// ============================================================================
int EAStringC_Insert_charptr(EAStringC* str, int pos, char* s) {
    return 0;
}

// ============================================================================
// EAStringC::Insert(int, char) (0x802bce40, 8 bytes) MATCHING
// Original: li r3,0 / blr
// Stub - always returns 0 (not implemented)
// ============================================================================
int EAStringC_Insert_char(EAStringC* str, int pos, char ch) {
    return 0;
}

// ============================================================================
// EAStringC::Trim (0x802bd884, 60 bytes) NON_MATCHING
// Original:
//   stwu r1,-24(r1) / mflr r0 / stmw r29,12(r1) / stw r0,28(r1)
//   mr r30,r3 / mr r29,r4
//   bl EAStringC::TrimLeft    (0x802bd5a0)
//   mr r3,r30 / mr r4,r29
//   bl EAStringC::TrimRight   (0x802bd710)
//   epilogue
// Trims whitespace (or specified chars) from both ends.
// ============================================================================
void EAStringC_Trim(EAStringC* str, char* chars) {
    EAStringC_TrimLeft(str, chars);
    EAStringC_TrimRight(str, chars);
}
