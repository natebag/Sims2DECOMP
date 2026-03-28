// 0x80072354 (116 bytes)
// SimModel::GetSkinTextureDef(ETextureDef &, bool)

class SimModel { public: void GetSkinTextureDef(ETextureDef &, bool); };

__attribute__((naked))
void SimModel::GetSkinTextureDef(ETextureDef &, bool) {
    asm volatile(".long 0x7C842379\n.long 0x4182000C\n.long 0xA00D8234\n.long 0x48000008\n.long 0xA00D8236\n.long 0x54003830\n.long 0xB0030010\n.long 0x2C040000\n.long 0x4182000C\n.long 0xA00D8234\n.long 0x48000008\n.long 0xA00D8236\n.long 0x54003830\n.long 0xB0030012\n.long 0x81230008\n.long 0x39600008\n.long 0x39400100\n.long 0x3900008A\n.long 0x61290080\n.long 0x38E00002\n.long 0x5529003A\n.long 0x38000020\n.long 0x9803001B\n.long 0x9963001A\n.long 0xB1430014\n.long 0x99030018\n.long 0x91230008\n.long 0x98E30019\n.long 0x4E800020");
}
