typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIGameInstanceName[];
extern int EIGameInstanceVtbl[];
extern void EIGameInstance_Ctor();
extern void EIGameInstance_Dtor();
extern void EIGameInstance_ReadWrite();
extern void EIGameInstance_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIGameInstanceTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIGameInstanceTypeHandle = RegisterTypeFunc(EIGameInstanceName, EIGameInstance_Ctor, EIGameInstance_Dtor, EIGameInstance_ReadWrite, 0, EIGameInstance_SizeData, EIGameInstanceVtbl);
    }
}
