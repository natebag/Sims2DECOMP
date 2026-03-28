typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EISpotLightName[];
extern int EISpotLightVtbl[];
extern void EISpotLight_Ctor();
extern void EISpotLight_Dtor();
extern void EISpotLight_ReadWrite();
extern void EISpotLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EISpotLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EISpotLightTypeHandle = RegisterTypeFunc(EISpotLightName, EISpotLight_Ctor, EISpotLight_Dtor, EISpotLight_ReadWrite, 0, EISpotLight_SizeData, EISpotLightVtbl);
    }
}
