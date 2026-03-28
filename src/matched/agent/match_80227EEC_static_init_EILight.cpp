typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EILightName[];
extern int EILightVtbl[];
extern void EILight_Ctor();
extern void EILight_Dtor();
extern void EILight_ReadWrite();
extern void EILight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EILightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EILightTypeHandle = RegisterTypeFunc(EILightName, EILight_Ctor, EILight_Dtor, EILight_ReadWrite, 0, EILight_SizeData, EILightVtbl);
    }
}
