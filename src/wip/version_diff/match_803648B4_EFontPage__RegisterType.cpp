typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EFontPageName[];
extern int EFontPageVtbl[];

extern void EFontPage_Ctor();
extern void EFontPage_Dtor();
extern void EFontPage_ReadWrite();
extern void EFontPage_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EFontPage {
    static void RegisterType(ushort typeId);
};

void EFontPage::RegisterType(ushort typeId) {
    RegisterTypeFunc(EFontPageName, EFontPage_Ctor, EFontPage_Dtor, EFontPage_ReadWrite, typeId, EFontPage_SizeData, EFontPageVtbl);
}
