typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERAnimName[];
extern int ERAnimVtbl[];

extern void ERAnim_Ctor();
extern void ERAnim_Dtor();
extern void ERAnim_ReadWrite();
extern void ERAnim_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERAnim {
    static void RegisterType(ushort typeId);
};

void ERAnim::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERAnimName, ERAnim_Ctor, ERAnim_Dtor, ERAnim_ReadWrite, typeId, ERAnim_SizeData, ERAnimVtbl);
}
