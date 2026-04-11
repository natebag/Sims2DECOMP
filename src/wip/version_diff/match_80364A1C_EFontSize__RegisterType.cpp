typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EFontSizeName[];
extern int EFontSizeVtbl[];

extern void EFontSize_Ctor();
extern void EFontSize_Dtor();
extern void EFontSize_ReadWrite();
extern void EFontSize_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EFontSize {
    static void RegisterType(ushort typeId);
};

void EFontSize::RegisterType(ushort typeId) {
    RegisterTypeFunc(EFontSizeName, EFontSize_Ctor, EFontSize_Dtor, EFontSize_ReadWrite, typeId, EFontSize_SizeData, EFontSizeVtbl);
}
