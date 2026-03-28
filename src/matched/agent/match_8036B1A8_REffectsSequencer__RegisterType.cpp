typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char REffectsSequencerName[];
extern int REffectsSequencerVtbl[];

extern void REffectsSequencer_Ctor();
extern void REffectsSequencer_Dtor();
extern void REffectsSequencer_ReadWrite();
extern void REffectsSequencer_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct REffectsSequencer {
    static void RegisterType(ushort typeId);
};

void REffectsSequencer::RegisterType(ushort typeId) {
    RegisterTypeFunc(REffectsSequencerName, REffectsSequencer_Ctor, REffectsSequencer_Dtor, REffectsSequencer_ReadWrite, typeId, REffectsSequencer_SizeData, REffectsSequencerVtbl);
}
