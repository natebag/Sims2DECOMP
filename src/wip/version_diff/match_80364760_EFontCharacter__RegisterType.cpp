typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EFontCharacterName[];
extern int EFontCharacterVtbl[];

extern void EFontCharacter_Ctor();
extern void EFontCharacter_Dtor();
extern void EFontCharacter_ReadWrite();
extern void EFontCharacter_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EFontCharacter {
    static void RegisterType(ushort typeId);
};

void EFontCharacter::RegisterType(ushort typeId) {
    RegisterTypeFunc(EFontCharacterName, EFontCharacter_Ctor, EFontCharacter_Dtor, EFontCharacter_ReadWrite, typeId, EFontCharacter_SizeData, EFontCharacterVtbl);
}
