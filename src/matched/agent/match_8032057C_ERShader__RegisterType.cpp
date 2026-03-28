typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char ERShaderName[];
extern int ERShaderVtbl[];

extern void ERShader_Ctor();
extern void ERShader_Dtor();
extern void ERShader_ReadWrite();
extern void ERShader_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct ERShader {
    static void RegisterType(ushort typeId);
};

void ERShader::RegisterType(ushort typeId) {
    RegisterTypeFunc(ERShaderName, ERShader_Ctor, ERShader_Dtor, ERShader_ReadWrite, typeId, ERShader_SizeData, ERShaderVtbl);
}
