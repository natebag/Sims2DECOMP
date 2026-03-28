typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EInstanceName[];
extern int EInstanceVtbl[];
extern void EInstance_Ctor();
extern void EInstance_Dtor();
extern void EInstance_ReadWrite();
extern void EInstance_SizeData();

extern int RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

extern int g_EInstanceTypeHandle;

void __static_initialization_and_destruction_0(int init, int priority) {
    if (priority == 0xFFFF && init != 0) {
        g_EInstanceTypeHandle = RegisterTypeFunc(EInstanceName, EInstance_Ctor, EInstance_Dtor, EInstance_ReadWrite, 1, EInstance_SizeData, EInstanceVtbl);
    }
}
