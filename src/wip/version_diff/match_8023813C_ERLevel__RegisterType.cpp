typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERLevelName[];
extern int ERLevelVtbl[];

extern void ERLevel_Ctor();
extern void ERLevel_Dtor();
extern void ERLevel_ReadWrite();
extern void ERLevel_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERLevel {
    static void RegisterType(ushort typeId);
};

void ERLevel::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERLevelName, ERLevel_Ctor, ERLevel_Dtor, ERLevel_ReadWrite, typeId, ERLevel_SizeData, ERLevelVtbl);
}
