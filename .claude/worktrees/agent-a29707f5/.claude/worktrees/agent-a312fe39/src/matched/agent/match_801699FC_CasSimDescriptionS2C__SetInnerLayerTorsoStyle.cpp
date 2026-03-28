// 0x801699FC (68 bytes)
// CasSimDescriptionS2C::SetInnerLayerTorsoStyle(CasSimPartsS2C &)

class CasSimDescriptionS2C { public: void SetInnerLayerTorsoStyle(CasSimPartsS2C &); };

__attribute__((naked))
void CasSimDescriptionS2C::SetInnerLayerTorsoStyle(CasSimPartsS2C &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x48000129\n.long 0x7C631B79\n.long 0x41820010\n.long 0x38000001\n.long 0x901F009C\n.long 0x48000008\n.long 0x907F009C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
