// 0x803646B8 EFontCharacter::Construct (16b)

typedef unsigned int u32;

struct EFontCharacterVTable;
extern EFontCharacterVTable g_EFontCharacterVTable;

struct EFontCharacter {
    u32 vtable;
};

void EFontCharacter_Construct(EFontCharacter* thisPtr) {
    thisPtr->vtable = (u32)&g_EFontCharacterVTable;
}
