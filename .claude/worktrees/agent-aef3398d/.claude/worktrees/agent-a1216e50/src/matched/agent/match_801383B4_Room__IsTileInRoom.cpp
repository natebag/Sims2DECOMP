// 0x801383B4 (108 bytes)
// Room::IsTileInRoom(CTilePt &)

class Room { public: void IsTileInRoom(CTilePt &); };

__attribute__((naked))
void Room::IsTileInRoom(CTilePt &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3BC30004\n.long 0x83E30004\n.long 0x801E0004\n.long 0x7C9D2378\n.long 0x7C1F0000\n.long 0x41820030\n.long 0x7FE3FB78\n.long 0x7FA4EB78\n.long 0x4BF7C389\n.long 0x2C030000\n.long 0x4182000C\n.long 0x38600001\n.long 0x48000018\n.long 0x801E0004\n.long 0x3BFF0003\n.long 0x7C1F0000\n.long 0x4082FFD8\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
