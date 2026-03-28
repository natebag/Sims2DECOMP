// AptXml.cpp - APT ActionScript XML type
// Source: libaptz.a(AptXml.cpp.obj)
// 3 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_xml.h"
#include "ui/apt_value.h"

// External
extern EAStringCInternalData EAStringC_s_EmptyInternalData;

// ============================================================================
// AptValueGC::IsGarbageCollected (0x802ba21c, 8 bytes) NON_MATCHING
// Duplicate instance for AptXml TU.
// Original: li r3,1 / blr
// ============================================================================
// Already defined in apt_value.cpp

// ============================================================================
// EAStringC::IsEmpty (0x802ba28c, 28 bytes) NON_MATCHING
// Duplicate instance for AptXml TU.
// Original:
//   lwz r0,0(r3)           ; load m_pData
//   lis r3,hi(EmptyData)   ; load address of empty internal data
//   addi r3,r3,lo(EmptyData)
//   xor r3,r0,r3           ; compare pointers
//   subfic r9,r3,0         ; r9 = -r3 (sets carry if r3 != 0)
//   adde r3,r9,r3          ; r3 = (r3 == 0) ? 1 : 0
//   blr
// Returns true if m_pData points to the static empty buffer.
// ============================================================================
// Already defined in apt_value.cpp

// ============================================================================
// EAStringC::EAStringC(char*) (0x802ba2a8, 48 bytes) NON_MATCHING
// Duplicate instance for AptXml TU.
// Calls EAStringC::InitFromBuffer to initialize from a C string.
// Original:
//   stwu r1,-16(r1) / mflr r0 / stmw r30,8(r1) / stw r0,20(r1)
//   mr r30,r3 (save this)
//   bl EAStringC::InitFromBuffer
//   mr r3,r30 (return this)
//   epilogue
// ============================================================================
// Already defined in apt_value.cpp
