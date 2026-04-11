typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EREdithTreeSetName[];
extern int EREdithTreeSetVtbl[];

extern void EREdithTreeSet_Ctor();
extern void EREdithTreeSet_Dtor();
extern void EREdithTreeSet_ReadWrite();
extern void EREdithTreeSet_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EREdithTreeSet {
    static void RegisterType(ushort typeId);
};

void EREdithTreeSet::RegisterType(ushort typeId) {
    RegisterTypeFunc(EREdithTreeSetName, EREdithTreeSet_Ctor, EREdithTreeSet_Dtor, EREdithTreeSet_ReadWrite, typeId, EREdithTreeSet_SizeData, EREdithTreeSetVtbl);
}
