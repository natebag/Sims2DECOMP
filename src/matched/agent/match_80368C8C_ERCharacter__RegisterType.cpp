typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERCharacterName[];
extern int ERCharacterVtbl[];

extern void ERCharacter_Ctor();
extern void ERCharacter_Dtor();
extern void ERCharacter_ReadWrite();
extern void ERCharacter_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERCharacter {
    static void RegisterType(ushort typeId);
};

void ERCharacter::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERCharacterName, ERCharacter_Ctor, ERCharacter_Dtor, ERCharacter_ReadWrite, typeId, ERCharacter_SizeData, ERCharacterVtbl);
}
