typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERSoundEventName[];
extern int ERSoundEventVtbl[];

extern void ERSoundEvent_Ctor();
extern void ERSoundEvent_Dtor();
extern void ERSoundEvent_ReadWrite();
extern void ERSoundEvent_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERSoundEvent {
    static void RegisterType(ushort typeId);
};

void ERSoundEvent::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERSoundEventName, ERSoundEvent_Ctor, ERSoundEvent_Dtor, ERSoundEvent_ReadWrite, typeId, ERSoundEvent_SizeData, ERSoundEventVtbl);
}
