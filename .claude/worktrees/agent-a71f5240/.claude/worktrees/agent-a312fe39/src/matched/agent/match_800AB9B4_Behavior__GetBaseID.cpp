// 0x800AB9B4 (64 bytes)
// Behavior::GetBaseID(short)

class Behavior { public: void GetBaseID(short); };

__attribute__((naked))
void Behavior::GetBaseID(short) {
    asm volatile(".long 0x38000000\n.long 0x2C030001\n.long 0x4182001C\n.long 0x4081002C\n.long 0x2C030002\n.long 0x41820018\n.long 0x2C030003\n.long 0x41820018\n.long 0x48000018\n.long 0x38000100\n.long 0x48000010\n.long 0x38001000\n.long 0x48000008\n.long 0x38002000\n.long 0x7C030378\n.long 0x4E800020");
}
