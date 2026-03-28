// 0x801410EC (72 bytes)
// cSimulatorImpl::SetSpeed(SimSpeed)

class cSimulatorImpl { public: void SetSpeed(SimSpeed); };

__attribute__((naked))
void cSimulatorImpl::SetSpeed(SimSpeed) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0xB09E0034\n.long 0x48000039\n.long 0x3D20803E\n.long 0x386000BD\n.long 0xC009D64C\n.long 0x38800000\n.long 0xD01E00A0\n.long 0x4BF731A1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
