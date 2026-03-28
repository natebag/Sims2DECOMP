typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERFlashName[];
extern int ERFlashVtbl[];

extern void ERFlash_Ctor();
extern void ERFlash_Dtor();
extern void ERFlash_ReadWrite();
extern void ERFlash_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERFlash {
    static void RegisterType(ushort typeId);
};

void ERFlash::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERFlashName, ERFlash_Ctor, ERFlash_Dtor, ERFlash_ReadWrite, typeId, ERFlash_SizeData, ERFlashVtbl);
}
