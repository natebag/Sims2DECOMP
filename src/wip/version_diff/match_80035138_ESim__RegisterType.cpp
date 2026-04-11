typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ESimName[];
extern int ESimVtbl[];

extern void ESim_Ctor();
extern void ESim_Dtor();
extern void ESim_ReadWrite();
extern void ESim_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ESim {
    static void RegisterType(ushort typeId);
};

void ESim::RegisterType(ushort typeId) {
    RegisterTypeFunc(ESimName, ESim_Ctor, ESim_Dtor, ESim_ReadWrite, typeId, ESim_SizeData, ESimVtbl);
}
