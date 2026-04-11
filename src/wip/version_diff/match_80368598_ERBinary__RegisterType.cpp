typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERBinaryName[];
extern int ERBinaryVtbl[];

extern void ERBinary_Ctor();
extern void ERBinary_Dtor();
extern void ERBinary_ReadWrite();
extern void ERBinary_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERBinary {
    static void RegisterType(ushort typeId);
};

void ERBinary::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERBinaryName, ERBinary_Ctor, ERBinary_Dtor, ERBinary_ReadWrite, typeId, ERBinary_SizeData, ERBinaryVtbl);
}
