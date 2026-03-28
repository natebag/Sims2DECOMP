typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERAmbientScoreName[];
extern int ERAmbientScoreVtbl[];

extern void ERAmbientScore_Ctor();
extern void ERAmbientScore_Dtor();
extern void ERAmbientScore_ReadWrite();
extern void ERAmbientScore_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERAmbientScore {
    static void RegisterType(ushort typeId);
};

void ERAmbientScore::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERAmbientScoreName, ERAmbientScore_Ctor, ERAmbientScore_Dtor, ERAmbientScore_ReadWrite, typeId, ERAmbientScore_SizeData, ERAmbientScoreVtbl);
}
