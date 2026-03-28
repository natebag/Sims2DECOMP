typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIPointAmbLightName[];
extern int EIPointAmbLightVtbl[];
extern void EIPointAmbLight_Ctor();
extern void EIPointAmbLight_Dtor();
extern void EIPointAmbLight_ReadWrite();
extern void EIPointAmbLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIPointAmbLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIPointAmbLightTypeHandle = RegisterTypeFunc(EIPointAmbLightName, EIPointAmbLight_Ctor, EIPointAmbLight_Dtor, EIPointAmbLight_ReadWrite, 0, EIPointAmbLight_SizeData, EIPointAmbLightVtbl);
    }
}
