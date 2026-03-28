// 0x801C294C (120 bytes)
// M2MTarget::UpdateSelection(int)

class M2MTarget { public: void UpdateSelection(int); };

__attribute__((naked))
void M2MTarget::UpdateSelection(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x2C040000\n.long 0x8163018C\n.long 0x40800024\n.long 0x380BFFFF\n.long 0x2C000000\n.long 0x9003018C\n.long 0x40800034\n.long 0x81230188\n.long 0x3929FFFF\n.long 0x9123018C\n.long 0x48000024\n.long 0x40810020\n.long 0x81230188\n.long 0x380B0001\n.long 0x9003018C\n.long 0x7C004800\n.long 0x4180000C\n.long 0x38000000\n.long 0x9003018C\n.long 0x8003018C\n.long 0x7C0B0000\n.long 0x41820008\n.long 0x4BFFDAB5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
