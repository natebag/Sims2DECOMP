typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPortalPointLightName[];
extern int EIPortalPointLightVtbl[];

extern void EIPortalPointLight_Ctor();
extern void EIPortalPointLight_Dtor();
extern void EIPortalPointLight_ReadWrite();
extern void EIPortalPointLight_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIPortalPointLight {
    static void RegisterType(ushort typeId);
};

void EIPortalPointLight::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIPortalPointLightName, EIPortalPointLight_Ctor, EIPortalPointLight_Dtor, EIPortalPointLight_ReadWrite, typeId, EIPortalPointLight_SizeData, EIPortalPointLightVtbl);
}
