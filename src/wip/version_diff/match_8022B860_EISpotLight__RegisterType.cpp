typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EISpotLightName[];
extern int EISpotLightVtbl[];

extern void EISpotLight_Ctor();
extern void EISpotLight_Dtor();
extern void EISpotLight_ReadWrite();
extern void EISpotLight_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EISpotLight {
    static void RegisterType(ushort typeId);
};

void EISpotLight::RegisterType(ushort typeId) {
    RegisterTypeFunc(EISpotLightName, EISpotLight_Ctor, EISpotLight_Dtor, EISpotLight_ReadWrite, typeId, EISpotLight_SizeData, EISpotLightVtbl);
}
