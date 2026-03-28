// 0x80050EB4 (96 bytes)
// ISimsObjectModel::OrientSubObjects(void)

class ISimsObjectModel { public: void OrientSubObjects(void); };

__attribute__((naked))
void ISimsObjectModel::OrientSubObjects(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x83FE0450\n.long 0x2C1F0000\n.long 0x41820030\n.long 0x807F0000\n.long 0x809E0328\n.long 0x81230000\n.long 0xA8090170\n.long 0x81290174\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x83FF0008\n.long 0x2C1F0000\n.long 0x4082FFD8\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
