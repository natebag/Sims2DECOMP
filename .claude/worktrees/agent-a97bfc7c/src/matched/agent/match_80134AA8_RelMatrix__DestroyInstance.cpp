// 0x80134AA8 (64 bytes)
// RelMatrix::DestroyInstance(RelMatrix *)

class RelMatrix { public: void DestroyInstance(RelMatrix *); };

__attribute__((naked))
void RelMatrix::DestroyInstance(RelMatrix *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B79\n.long 0x41820020\n.long 0x812B0000\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
