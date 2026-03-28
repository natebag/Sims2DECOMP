// 0x8006ECBC (92 bytes)
// SimImageMaker::OverrideLights(ELights &)

class SimImageMaker { public: void OverrideLights(ELights &); };

__attribute__((naked))
void SimImageMaker::OverrideLights(ELights &) {
    asm volatile(".long 0x386300F8\n.long 0x392000F0\n.long 0x80040000\n.long 0x3529FFE8\n.long 0x90030000\n.long 0x80040004\n.long 0x90030004\n.long 0x80040008\n.long 0x90030008\n.long 0x8004000C\n.long 0x9003000C\n.long 0x80040010\n.long 0x90030010\n.long 0x80040014\n.long 0x38840018\n.long 0x90030014\n.long 0x38630018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x90030000\n.long 0x80040004\n.long 0x90030004\n.long 0x4E800020");
}
