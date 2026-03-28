typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char REffectsEmitterName[];
extern int REffectsEmitterVtbl[];

extern void REffectsEmitter_Ctor();
extern void REffectsEmitter_Dtor();
extern void REffectsEmitter_ReadWrite();
extern void REffectsEmitter_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct REffectsEmitter {
    static void RegisterType(ushort typeId);
};

void REffectsEmitter::RegisterType(ushort typeId) {
    RegisterTypeFunc(REffectsEmitterName, REffectsEmitter_Ctor, REffectsEmitter_Dtor, REffectsEmitter_ReadWrite, typeId, REffectsEmitter_SizeData, REffectsEmitterVtbl);
}
