typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERModelName[];
extern int ERModelVtbl[];

extern void ERModel_Ctor();
extern void ERModel_Dtor();
extern void ERModel_ReadWrite();
extern void ERModel_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERModel {
    static void RegisterType(ushort typeId);
};

void ERModel::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERModelName, ERModel_Ctor, ERModel_Dtor, ERModel_ReadWrite, typeId, ERModel_SizeData, ERModelVtbl);
}
