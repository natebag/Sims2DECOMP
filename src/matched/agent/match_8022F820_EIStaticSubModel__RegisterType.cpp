typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIStaticSubModelName[];
extern int EIStaticSubModelVtbl[];

extern void EIStaticSubModel_Ctor();
extern void EIStaticSubModel_Dtor();
extern void EIStaticSubModel_ReadWrite();
extern void EIStaticSubModel_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIStaticSubModel {
    static void RegisterType(ushort typeId);
};

void EIStaticSubModel::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIStaticSubModelName, EIStaticSubModel_Ctor, EIStaticSubModel_Dtor, EIStaticSubModel_ReadWrite, typeId, EIStaticSubModel_SizeData, EIStaticSubModelVtbl);
}
