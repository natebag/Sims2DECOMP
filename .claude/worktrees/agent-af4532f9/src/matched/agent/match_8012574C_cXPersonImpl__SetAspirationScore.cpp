// 0x8012574C (92 bytes)
// cXPersonImpl::SetAspirationScore(float)

class cXPersonImpl { public: void SetAspirationScore(float); };

__attribute__((naked))
void cXPersonImpl::SetAspirationScore(float) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D20803E\n.long 0x81030004\n.long 0xC009CD54\n.long 0x3D60803E\n.long 0x81480004\n.long 0x3D20803E\n.long 0xED810024\n.long 0xC1ABCD58\n.long 0xC029CD5C\n.long 0x38800000\n.long 0xA86A0070\n.long 0x800A0074\n.long 0x7C681A14\n.long 0x7C0803A6\n.long 0xEC2C0B78\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
