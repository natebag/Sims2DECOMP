typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EFontDataName[];
extern int EFontDataVtbl[];

extern void EFontData_Ctor();
extern void EFontData_Dtor();
extern void EFontData_ReadWrite();
extern void EFontData_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EFontData {
    static void RegisterType(ushort typeId);
};

void EFontData::RegisterType(ushort typeId) {
    RegisterTypeFunc(EFontDataName, EFontData_Ctor, EFontData_Dtor, EFontData_ReadWrite, typeId, EFontData_SizeData, EFontDataVtbl);
}
