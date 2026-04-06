// 0x803646C8 EFontCharacter::Destruct (16b)

typedef unsigned int u32;

struct EFontCharacterVTable;
extern EFontCharacterVTable g_EFontCharacterVTable_Destruct;

struct EFontCharacter {
    u32 vtable;
};

void EFontCharacter_Destruct(EFontCharacter* thisPtr) {
    thisPtr->vtable = (u32)&g_EFontCharacterVTable_Destruct;
}
