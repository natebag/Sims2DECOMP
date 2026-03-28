// apt_ea_string_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: EAString.cpp.obj
// 15 functions, 5176 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// EAStringC::operator+(EAStringC &) const - 0x802BC2C0 | 276 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__operator_const(void* self, void* p1) {
    // Stack: 48 bytes
    // -> EAStringC::EAStringC(unsigned int)
    // -> memcpy
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// EAStringC::operator+(char *) const - 0x802BC4AC | 280 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__operator_const(void* self, char* p1) {
    // Stack: 48 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> strlen
    // -> EAStringC::EAStringC(unsigned int)
    // -> memcpy
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// operator+(char *, EAStringC &) - 0x802BC6C4 | 276 bytes
// ============================================================================
// NON_MATCHING
void operator_plus_charptr_EAStringC(char* p1, void* p2) {
    // Stack: 48 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> strlen
    // -> EAStringC::EAStringC(unsigned int)
    // -> memcpy
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// EAStringC::AppendFormat(char *,...) - 0x802BC960 | 292 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__AppendFormat(void* self, char* p1) {
    // Stack: 168 bytes
    // -> strlen
    // -> EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int)
    // -> vsnprintf
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// EAStringC::Delete(int, int) - 0x802BCCA0 | 336 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__Delete(void* self, int p1, int p2) {
    // Stack: 32 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int)
    // -> memcpy
    // Accesses globals via r13 (SDA)

    // Remove element
}

// ============================================================================
// EAStringC::Replace(char *, char *) - 0x802BCE48 | 464 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__Replace(void* self, char* p1, char* p2) {
    // Stack: 72 bytes
    // -> strlen
    // -> strstr
    // -> EAStringC::EAStringC(unsigned int)
    // -> memcpy
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// EAStringC::TrimLeft(char *) - 0x802BD5A0 | 368 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__TrimLeft(void* self, char* p1) {
    // Stack: 48 bytes
    // -> strchr
    // -> EAStringC::Mid(int) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// EAStringC::TrimRight(char *) - 0x802BD710 | 372 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__TrimRight(void* self, char* p1) {
    // Stack: 48 bytes
    // -> strchr
    // -> EAStringC::Left(int) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// EAStringC::UTF8_Mid(int, int) const - 0x802BDDE0 | 292 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_Mid_const(void* self, int p1, int p2) {
    // Stack: 40 bytes
    // -> EAStringC::UTF8_ReadCharacter(char *, int *)
    // -> EAStringC::Mid(int) const
    // -> EAStringC::Mid(int, int) const
    // Contains loop(s)

}

// ============================================================================
// EAStringC::UTF8_Append(char *, int) - 0x802BDF04 | 260 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_Append(void* self, char* p1, int p2) {
    // Stack: 24 bytes
    // -> EAStringC::Append(char *, unsigned int)
    // Contains loop(s)

}

// ============================================================================
// EAStringC::UTF8_Find(char *, int) const - 0x802BE008 | 260 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_Find_const(void* self, char* p1, int p2) {
    // Stack: 40 bytes
    // -> EAStringC::UTF8_ReadCharacter(char *, int *)
    // -> EAStringC::Find(char *, int) const
    // Contains loop(s)

    // Search/lookup
}

// ============================================================================
// EAStringC::UTF8_MakeLower(void) - 0x802BE10C | 448 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_MakeLower(void* self) {
    // Stack: 24 bytes
    // -> EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int)
    // Contains loop(s)

}

// ============================================================================
// EAStringC::UTF8_MakeUpper(void) - 0x802BE2CC | 448 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_MakeUpper(void* self) {
    // Stack: 24 bytes
    // -> EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int)
    // Contains loop(s)

}

// ============================================================================
// EAStringC::UTF8_Initialize(int) - 0x802BE48C | 448 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__UTF8_Initialize(void* self, int p1) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::ReserveSize(unsigned int)
    // Accesses globals via r13 (SDA)

    // Initialize subsystem
    // Sets up global state
}

// ============================================================================
// EAStringC::ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int) - 0x802BE64C | 356 bytes
// ============================================================================
// NON_MATCHING
void EAStringC__ChangeBuffer(void* self, int p1, int p2, int p3, void* p4, int p5) {
    // Stack: 48 bytes
    // -> memmove
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> memcpy
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}
