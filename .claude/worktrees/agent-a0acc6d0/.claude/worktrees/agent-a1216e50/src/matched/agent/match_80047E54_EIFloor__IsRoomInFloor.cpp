// 0x80047E54 (80 bytes)
// EIFloor::IsRoomInFloor(unsigned short)

class EIFloor { public: void IsRoomInFloor(unsigned short); };

__attribute__((naked))
void EIFloor::IsRoomInFloor(unsigned short) {
    asm volatile(".long 0x8003007C\n.long 0x7C040000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x80030080\n.long 0x39200000\n.long 0x7C090000\n.long 0x40800028\n.long 0x7C0B0378\n.long 0x38630084\n.long 0xA0030000\n.long 0x38630002\n.long 0x7C040000\n.long 0x4182FFD4\n.long 0x39290001\n.long 0x7C095800\n.long 0x4180FFE8\n.long 0x38600000\n.long 0x4E800020");
}
