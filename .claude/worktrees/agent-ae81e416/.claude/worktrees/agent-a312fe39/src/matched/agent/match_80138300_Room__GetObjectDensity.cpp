// 0x80138300 (88 bytes)
// Room::GetObjectDensity(void)

class Room { public: void GetObjectDensity(void); };

__attribute__((naked))
void Room::GetObjectDensity(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x80030054\n.long 0x3CE04330\n.long 0x8123004C\n.long 0x6C008000\n.long 0x7D6A5B78\n.long 0x9001000C\n.long 0x6D298000\n.long 0x3D00803E\n.long 0x90E10008\n.long 0xC9A8D3C8\n.long 0xC8010008\n.long 0x9121000C\n.long 0xFC006828\n.long 0x90E10008\n.long 0xFC000018\n.long 0xC8210008\n.long 0xFC216828\n.long 0xFC200818\n.long 0xEC200824\n.long 0x38210010\n.long 0x4E800020");
}
