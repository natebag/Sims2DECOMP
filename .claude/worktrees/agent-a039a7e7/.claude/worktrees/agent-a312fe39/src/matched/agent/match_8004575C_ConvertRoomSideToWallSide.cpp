// 0x8004575C (84 bytes)
// ConvertRoomSideToWallSide(Room::Sides)

class ConvertRoomSideToWallSide(Room { public: void Sides)(); };

__attribute__((naked))
void ConvertRoomSideToWallSide(Room::Sides)() {
    asm volatile(".long 0x2C030002\n.long 0x41820040\n.long 0x41810010\n.long 0x2C030001\n.long 0x4182001C\n.long 0x48000038\n.long 0x2C030003\n.long 0x41820018\n.long 0x2C030004\n.long 0x41820018\n.long 0x48000024\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600003\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600004\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
