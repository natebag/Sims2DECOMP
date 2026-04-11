typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPointAmbLightName[];
extern int EIPointAmbLightVtbl[];

extern void EIPointAmbLight_Ctor();
extern void EIPointAmbLight_Dtor();
extern void EIPointAmbLight_ReadWrite();
extern void EIPointAmbLight_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIPointAmbLight {
    static void RegisterType(ushort typeId);
};

void EIPointAmbLight::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIPointAmbLightName, EIPointAmbLight_Ctor, EIPointAmbLight_Dtor, EIPointAmbLight_ReadWrite, typeId, EIPointAmbLight_SizeData, EIPointAmbLightVtbl);
}
