#ifndef APT_CHARACTER_BUTTON_H
#define APT_CHARACTER_BUTTON_H

#include "types.h"
#include "ui/apt_value.h"
#include "ui/apt_character.h"

// ============================================================================
// AptCharacterButtonInst - button character instance
// Source: libaptz.a(AptCharacterInstButton.cpp.obj)
//
// Layout extends AptCharacterInst:
//   0x00-0x0B: AptValue base
//   0x0C: AptValue* m_nativeHash (from AptCharacterInst)
//   0x10: u32 m_gcFlag (from AptCharacterInst)
//   0x1C: AptDisplayList (embedded, PreDestroy calls AptDisplayList::PreDestroy at this+28)
// ============================================================================
class AptCharacterButtonInst : public AptCharacterInst {
public:
    // 0x1C: AptDisplayList embedded (accessed via addi r3,r3,28 = 0x1C)

    AptCharacterButtonInst();
    ~AptCharacterButtonInst();

    void PreDestroy();

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

#endif // APT_CHARACTER_BUTTON_H
