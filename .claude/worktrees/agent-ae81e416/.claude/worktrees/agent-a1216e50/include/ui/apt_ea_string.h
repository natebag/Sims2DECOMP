#ifndef APT_EA_STRING_H
#define APT_EA_STRING_H

#include "types.h"
#include "ui/apt_value.h"

// ============================================================================
// EAStringC extended API
// Source: libaptz.a(EAString.cpp.obj)
//
// EAStringC internal data layout:
//   0x00: u16 m_refCount
//   0x02: u16 m_bufferSize (total capacity including null)
//   0x04: u16 m_length (string length in chars)
//   0x06: u16 m_pad
//   0x08+: char m_data[] (string data)
// ============================================================================

// Additional methods on EAStringC beyond what's in apt_value.h
// These are implemented in EAString.cpp.obj

// ============================================================================
// CBPushZero enum for ChangeBuffer
// ============================================================================
namespace EAStringCNS {
    enum CBPushZero {
        CB_NO_PUSH_ZERO = 0,
        CB_PUSH_ZERO = 1
    };
}

// StringPool - global string interning pool
// Source: libaptz.a(StringPool.cpp.obj)
class StringPool {
public:
    static void* spPool;
};

// Free function from StringPool.cpp.obj
void __static_initialization_and_destruction_0(int action, unsigned int priority);

#endif // APT_EA_STRING_H
