typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPointLightName[];
extern int EIPointLightVtbl[];

extern void EIPointLight_Ctor();
extern void EIPointLight_Dtor();
extern void EIPointLight_ReadWrite();
extern void EIPointLight_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIPointLight {
    static void RegisterType(ushort typeId);
};

void EIPointLight::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIPointLightName, EIPointLight_Ctor, EIPointLight_Dtor, EIPointLight_ReadWrite, typeId, EIPointLight_SizeData, EIPointLightVtbl);
}
