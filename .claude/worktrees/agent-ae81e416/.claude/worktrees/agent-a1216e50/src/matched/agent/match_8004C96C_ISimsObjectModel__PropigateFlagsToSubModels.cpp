// 0x8004C96C (100 bytes)
// ISimsObjectModel::PropigateFlagsToSubModels(void)

class ISimsObjectModel { public: void PropigateFlagsToSubModels(void); };

__attribute__((naked))
void ISimsObjectModel::PropigateFlagsToSubModels(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x83FE0450\n.long 0x2C1F0000\n.long 0x41820034\n.long 0x807F0000\n.long 0x809E032C\n.long 0x81230320\n.long 0x38630320\n.long 0xA8090018\n.long 0x8129001C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x83FF0008\n.long 0x2C1F0000\n.long 0x4082FFD4\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
