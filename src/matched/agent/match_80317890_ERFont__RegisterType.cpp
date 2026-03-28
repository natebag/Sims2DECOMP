typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERFontName[];
extern int ERFontVtbl[];

extern void ERFont_Ctor();
extern void ERFont_Dtor();
extern void ERFont_ReadWrite();
extern void ERFont_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERFont {
    static void RegisterType(ushort typeId);
};

void ERFont::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERFontName, ERFont_Ctor, ERFont_Dtor, ERFont_ReadWrite, typeId, ERFont_SizeData, ERFontVtbl);
}
