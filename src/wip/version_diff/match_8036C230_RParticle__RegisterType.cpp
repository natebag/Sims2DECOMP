typedef unsigned short ushort;
typedef void (*FuncPtr)();

extern char RParticleName[];
extern int RParticleVtbl[];

extern void RParticle_Ctor();
extern void RParticle_Dtor();
extern void RParticle_ReadWrite();
extern void RParticle_SizeData();

extern void RegisterTypeFunc(char *name, FuncPtr ctor, FuncPtr dtor, FuncPtr readwrite, ushort typeId, FuncPtr sizeData, int *vtbl);

struct RParticle {
    static void RegisterType(ushort typeId);
};

void RParticle::RegisterType(ushort typeId) {
    RegisterTypeFunc(RParticleName, RParticle_Ctor, RParticle_Dtor, RParticle_ReadWrite, typeId, RParticle_SizeData, RParticleVtbl);
}
