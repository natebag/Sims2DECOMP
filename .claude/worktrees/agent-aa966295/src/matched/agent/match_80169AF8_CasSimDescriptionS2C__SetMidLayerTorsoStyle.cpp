// 0x80169AF8 (64 bytes)
// CasSimDescriptionS2C::SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C &)

class CasSimDescriptionS2C { public: void SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C &); };

__attribute__((naked))
void CasSimDescriptionS2C::SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x909E00A8\n.long 0x7CA42B78\n.long 0x480001A1\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x4BFFFF3D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
