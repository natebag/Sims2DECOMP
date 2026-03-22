// apt_sound_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptSound.cpp.obj
// 3 functions, 1200 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// SoundMembersIndex::in_word_set(char *, unsigned int) - 0x802AB740 | 264 bytes
// ============================================================================
// NON_MATCHING
void SoundMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptSound::sMethod_attachSound(AptValue *, int) - 0x802AB9B0 | 316 bytes
// ============================================================================
// NON_MATCHING
void AptSound__sMethod_attachSound(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> strcasecmp
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptSound::objectMemberLookup(AptValue *, EAStringC *) const - 0x802ABB58 | 620 bytes
// ============================================================================
// NON_MATCHING
void AptSound__objectMemberLookup_const(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> SoundMembersIndex::in_word_set(char *, unsigned int)
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // Accesses globals via r13 (SDA)

    // Search/lookup
}
