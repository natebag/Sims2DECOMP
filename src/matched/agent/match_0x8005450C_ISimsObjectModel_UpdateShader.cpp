// FLAGS: -msdata=eabi -G 8
// 0x8005450C ISimsObjectModel::UpdateShader (80b)
extern void ChangeShader(void*, unsigned int, unsigned int);

struct ShaderDef {
    char pad[12];
    unsigned int matId;
    unsigned int shaderId;
};

struct ShaderSlot {
    char pad[12];
    unsigned int matId;
    unsigned int shaderId;
};

void UpdateShader(void* self, ShaderDef* def) {
    ShaderSlot* slot = (ShaderSlot*)((char*)self + 0x420);
    if (slot->shaderId == def->shaderId) return;
    if (def->shaderId == 0) return;
    slot->shaderId = def->shaderId;
    slot->matId = def->matId;
    ChangeShader(self, def->matId, def->shaderId);
}
