// 0x8034405C (80 bytes)
// ENgcRenderer::ModelMatrices(EMat4 *, int)

class ENgcRenderer { public: void ModelMatrices(EMat4 *, int); };

__attribute__((naked))
void ENgcRenderer::ModelMatrices(EMat4 *, int) {
    asm volatile(".long 0x54A018F8\n.long 0x90A34570\n.long 0x39630770\n.long 0x7C842379\n.long 0x41820034\n.long 0x2C0B0000\n.long 0x4182002C\n.long 0x2C000000\n.long 0x41820024\n.long 0x7C0903A6\n.long 0x81240000\n.long 0x81440004\n.long 0x38840008\n.long 0x912B0000\n.long 0x914B0004\n.long 0x396B0008\n.long 0x4200FFE8\n.long 0x38000001\n.long 0x90030510\n.long 0x4E800020");
}
