typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EResourceName[];
extern int EResourceVtbl[];

extern void EResource_Ctor();
extern void EResource_Dtor();
extern void EResource_ReadWrite();
extern void EResource_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EResource {
    static void RegisterType(ushort typeId);
};

void EResource::RegisterType(ushort typeId) {
    RegisterTypeFunc(EResourceName, EResource_Ctor, EResource_Dtor, EResource_ReadWrite, typeId, EResource_SizeData, EResourceVtbl);
}
