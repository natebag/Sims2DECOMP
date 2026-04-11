typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERDatasetName[];
extern int ERDatasetVtbl[];

extern void ERDataset_Ctor();
extern void ERDataset_Dtor();
extern void ERDataset_ReadWrite();
extern void ERDataset_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERDataset {
    static void RegisterType(ushort typeId);
};

void ERDataset::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERDatasetName, ERDataset_Ctor, ERDataset_Dtor, ERDataset_ReadWrite, typeId, ERDataset_SizeData, ERDatasetVtbl);
}
