// apt_text_format_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptTextFormat.cpp.obj
// 3 functions, 1204 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// TextFormatMembersIndex::in_word_set(char *, unsigned int) - 0x802AF0AC | 296 bytes
// ============================================================================
// NON_MATCHING
void TextFormatMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptTextFormat::AptTextFormat(AptValue *, float, unsigned int, int, int, int, int, int, AptValue *, int, int, int, int) - 0x802AFC14 | 552 bytes
// ============================================================================
// NON_MATCHING
void AptTextFormat__AptTextFormat(void* self, void* p1, float p2, int p3, int p4, int p5, int p6, int p7, int p8, void* p9, int p10, int p11, int p12, int p13) {
    // Stack: 64 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::isUndefined(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::operator==(char *) const
    // ... and 1 more calls
    // Uses floating point

    // Initialize members
    // Object size >= 0x54
}

// ============================================================================
// AptTextFormat::AptTextFormat(TextFormat *) - 0x802AFE3C | 356 bytes
// ============================================================================
// NON_MATCHING
void AptTextFormat__AptTextFormat(void* self, void* p1) {
    // Stack: 40 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> EAStringC::EAStringC(char *)
    // -> TextFormat::copyTextFormatObj(TextFormat *)
    // -> EAStringC::operator!=(char *) const
    // -> EAStringC::operator=(EAStringC &)
    // Uses floating point

    // Initialize members
    // Object size >= 0x13B8
}
