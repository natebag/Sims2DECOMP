typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIDirLightName[];
extern int EIDirLightVtbl[];
extern void EIDirLight_Ctor();
extern void EIDirLight_Dtor();
extern void EIDirLight_ReadWrite();
extern void EIDirLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIDirLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIDirLightTypeHandle = RegisterTypeFunc(EIDirLightName, EIDirLight_Ctor, EIDirLight_Dtor, EIDirLight_ReadWrite, 0, EIDirLight_SizeData, EIDirLightVtbl);
    }
}
