typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPointLightName[];
extern int EIPointLightVtbl[];
extern void EIPointLight_Ctor();
extern void EIPointLight_Dtor();
extern void EIPointLight_ReadWrite();
extern void EIPointLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIPointLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIPointLightTypeHandle = RegisterTypeFunc(EIPointLightName, EIPointLight_Ctor, EIPointLight_Dtor, EIPointLight_ReadWrite, 0, EIPointLight_SizeData, EIPointLightVtbl);
    }
}
