// 0x800B90A8 (64 bytes)
// cGZSndSys::removeFromList(cGZSnd *)

class cGZSndSys { public: void removeFromList(cGZSnd *); };

__attribute__((naked))
void cGZSndSys::removeFromList(cGZSnd *) {
    asm volatile(".long 0x80030404\n.long 0x39200000\n.long 0x7C002000\n.long 0x41820014\n.long 0x7C090378\n.long 0x8009003C\n.long 0x7C002000\n.long 0x4082FFF4\n.long 0x2C090000\n.long 0x41820010\n.long 0x8004003C\n.long 0x9009003C\n.long 0x4E800020\n.long 0x8004003C\n.long 0x90030404\n.long 0x4E800020");
}
