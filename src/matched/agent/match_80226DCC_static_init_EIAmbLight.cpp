typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIAmbLightName[];
extern int EIAmbLightVtbl[];
extern void EIAmbLight_Ctor();
extern void EIAmbLight_Dtor();
extern void EIAmbLight_ReadWrite();
extern void EIAmbLight_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EIAmbLightTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EIAmbLightTypeHandle = RegisterTypeFunc(EIAmbLightName, EIAmbLight_Ctor, EIAmbLight_Dtor, EIAmbLight_ReadWrite, 0, EIAmbLight_SizeData, EIAmbLightVtbl);
    }
}
