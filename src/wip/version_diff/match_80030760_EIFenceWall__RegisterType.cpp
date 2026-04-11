typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char EIFenceWallName[];
extern int EIFenceWallVtbl[];

extern void EIFenceWall_Ctor();
extern void EIFenceWall_Dtor();
extern void EIFenceWall_ReadWrite();
extern void EIFenceWall_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct EIFenceWall {
    static void RegisterType(ushort typeId);
};

void EIFenceWall::RegisterType(ushort typeId) {
    RegisterTypeFunc(EIFenceWallName, EIFenceWall_Ctor, EIFenceWall_Dtor, EIFenceWall_ReadWrite, typeId, EIFenceWall_SizeData, EIFenceWallVtbl);
}
