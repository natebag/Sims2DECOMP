// 0x80041F98 (76 bytes)
// EGlobal::CheckForZeroExtentOverride(cXObject *)

class EGlobal { public: void CheckForZeroExtentOverride(cXObject *); };

__attribute__((naked))
void EGlobal::CheckForZeroExtentOverride(cXObject *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81240004\n.long 0x80090314\n.long 0xA8690310\n.long 0x7C0803A6\n.long 0x7C641A14\n.long 0x4E800021\n.long 0xA00300B6\n.long 0x38600001\n.long 0x5400077C\n.long 0x2C000000\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
