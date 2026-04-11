typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERSoundTrackDataName[];
extern int ERSoundTrackDataVtbl[];

extern void ERSoundTrackData_Ctor();
extern void ERSoundTrackData_Dtor();
extern void ERSoundTrackData_ReadWrite();
extern void ERSoundTrackData_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERSoundTrackData {
    static void RegisterType(ushort typeId);
};

void ERSoundTrackData::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERSoundTrackDataName, ERSoundTrackData_Ctor, ERSoundTrackData_Dtor, ERSoundTrackData_ReadWrite, typeId, ERSoundTrackData_SizeData, ERSoundTrackDataVtbl);
}
