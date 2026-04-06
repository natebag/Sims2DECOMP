// FLAGS: -msdata=eabi -G 8
// 0x802F9DC8 EShader::Create (68b)
extern void EShaderDef_assign(void*, void*);
extern void EShader_AddToUpdateList(void*);

struct EShader {
    int pad;
    unsigned int flags;
};

int EShader_Create(EShader* self, void* def) {
    EShaderDef_assign(self, def);
    if (self->flags & 0x84000000u) {
        EShader_AddToUpdateList(self);
    }
    return 1;
}
