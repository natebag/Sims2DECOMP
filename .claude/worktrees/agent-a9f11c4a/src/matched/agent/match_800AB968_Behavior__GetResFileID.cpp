// 0x800AB968 (76 bytes)
// Behavior::GetResFileID(short)

class Behavior { public: void GetResFileID(short); };

__attribute__((naked))
void Behavior::GetResFileID(short) {
    asm volatile(".long 0x3804FF00\n.long 0x28002228\n.long 0x4081000C\n.long 0x3860FFFF\n.long 0x4E800020\n.long 0x2C040FFF\n.long 0x4181000C\n.long 0x806D8398\n.long 0x4E800020\n.long 0x2C041FFF\n.long 0x41810010\n.long 0x81230004\n.long 0x80690004\n.long 0x4E800020\n.long 0x2C042328\n.long 0x4181FFD0\n.long 0x81230004\n.long 0x80690008\n.long 0x4E800020");
}
