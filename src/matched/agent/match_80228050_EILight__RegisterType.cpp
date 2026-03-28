typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EILightName[];
extern int EILightVtbl[];

extern void EILight_Ctor();
extern void EILight_Dtor();
extern void EILight_ReadWrite();
extern void EILight_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EILight {
    static void RegisterType(ushort typeId);
};

void EILight::RegisterType(ushort typeId) {
    RegisterTypeFunc(EILightName, EILight_Ctor, EILight_Dtor, EILight_ReadWrite, typeId, EILight_SizeData, EILightVtbl);
}
