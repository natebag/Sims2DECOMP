typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPortalPointLightName[];
extern int EIPortalPointLightVtbl[];
extern void EIPortalPointLight_Ctor();
extern void EIPortalPointLight_Dtor();
extern void EIPortalPointLight_ReadWrite();
extern void EIPortalPointLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIPortalPointLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIPortalPointLightTypeHandle = RegisterTypeFunc(EIPortalPointLightName, EIPortalPointLight_Ctor, EIPortalPointLight_Dtor, EIPortalPointLight_ReadWrite, 0, EIPortalPointLight_SizeData, EIPortalPointLightVtbl);
    }
}
