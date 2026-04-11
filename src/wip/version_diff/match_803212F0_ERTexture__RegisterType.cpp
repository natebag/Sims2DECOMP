typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERTextureName[];
extern int ERTextureVtbl[];

extern void ERTexture_Ctor();
extern void ERTexture_Dtor();
extern void ERTexture_ReadWrite();
extern void ERTexture_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERTexture {
    static void RegisterType(ushort typeId);
};

void ERTexture::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERTextureName, ERTexture_Ctor, ERTexture_Dtor, ERTexture_ReadWrite, typeId, ERTexture_SizeData, ERTextureVtbl);
}
