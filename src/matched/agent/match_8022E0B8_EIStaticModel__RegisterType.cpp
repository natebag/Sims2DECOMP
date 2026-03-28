typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIStaticModelName[];
extern int EIStaticModelVtbl[];

extern void EIStaticModel_Ctor();
extern void EIStaticModel_Dtor();
extern void EIStaticModel_ReadWrite();
extern void EIStaticModel_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIStaticModel {
    static void RegisterType(ushort typeId);
};

void EIStaticModel::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIStaticModelName, EIStaticModel_Ctor, EIStaticModel_Dtor, EIStaticModel_ReadWrite, typeId, EIStaticModel_SizeData, EIStaticModelVtbl);
}
