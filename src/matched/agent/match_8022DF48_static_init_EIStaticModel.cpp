typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIStaticModelName[];
extern int EIStaticModelVtbl[];
extern void EIStaticModel_Ctor();
extern void EIStaticModel_Dtor();
extern void EIStaticModel_ReadWrite();
extern void EIStaticModel_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIStaticModelTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIStaticModelTypeHandle = RegisterTypeFunc(EIStaticModelName, EIStaticModel_Ctor, EIStaticModel_Dtor, EIStaticModel_ReadWrite, 0, EIStaticModel_SizeData, EIStaticModelVtbl);
    }
}
