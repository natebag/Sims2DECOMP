// 0x80138684 (80 bytes)
// Room::GetAmbientLight(void) const

class Room { public: void GetAmbientLight(void) const; };

__attribute__((naked))
void Room::GetAmbientLight(void) const {
    asm volatile(".long 0x80030094\n.long 0x2C000000\n.long 0x4082003C\n.long 0x80030090\n.long 0xC0230080\n.long 0x2C000000\n.long 0x4D820020\n.long 0x8003009C\n.long 0x2C000000\n.long 0x4C820020\n.long 0x800300A0\n.long 0x2C000000\n.long 0x4C810020\n.long 0x3D20803E\n.long 0xC009D3D4\n.long 0xFC010000\n.long 0x4C800020\n.long 0x3D20803E\n.long 0xC029D3D4\n.long 0x4E800020");
}
