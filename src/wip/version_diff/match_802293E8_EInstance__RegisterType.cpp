typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EInstanceName[];
extern int EInstanceVtbl[];

extern void EInstance_Ctor();
extern void EInstance_Dtor();
extern void EInstance_ReadWrite();
extern void EInstance_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EInstance {
    static void RegisterType(ushort typeId);
};

void EInstance::RegisterType(ushort typeId) {
    RegisterTypeFunc(EInstanceName, EInstance_Ctor, EInstance_Dtor, EInstance_ReadWrite, typeId, EInstance_SizeData, EInstanceVtbl);
}
