// 0x80188CC4 (120 bytes)
// HUDTarget::NotifyMenuRemoveObj(cXObject *)

class HUDTarget { public: void NotifyMenuRemoveObj(cXObject *); };

__attribute__((naked))
void HUDTarget::NotifyMenuRemoveObj(cXObject *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x3BFE0740\n.long 0x7FE3FB78\n.long 0x4BFFA6F5\n.long 0x2C030000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFB6B5\n.long 0x3D208047\n.long 0x80095C70\n.long 0x2C000000\n.long 0x41820024\n.long 0x3BFE07F4\n.long 0x7FA4EB78\n.long 0x7FE3FB78\n.long 0x4BFFA6C5\n.long 0x2C030000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFB685\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
