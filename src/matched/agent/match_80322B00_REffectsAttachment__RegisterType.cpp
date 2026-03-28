typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char REffectsAttachmentName[];
extern int REffectsAttachmentVtbl[];

extern void REffectsAttachment_Ctor();
extern void REffectsAttachment_Dtor();
extern void REffectsAttachment_ReadWrite();
extern void REffectsAttachment_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct REffectsAttachment {
    static void RegisterType(ushort typeId);
};

void REffectsAttachment::RegisterType(ushort typeId) {
    RegisterTypeFunc(REffectsAttachmentName, REffectsAttachment_Ctor, REffectsAttachment_Dtor, REffectsAttachment_ReadWrite, typeId, REffectsAttachment_SizeData, REffectsAttachmentVtbl);
}
