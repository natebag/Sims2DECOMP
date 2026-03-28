// 0x800B90F8 (84 bytes)
// cGZSndSys::removeFromList(cGZMusic *)

class cGZSndSys { public: void removeFromList(cGZMusic *); };

__attribute__((naked))
void cGZSndSys::removeFromList(cGZMusic *) {
    asm volatile(".long 0x80030408\n.long 0x39200000\n.long 0x7C002000\n.long 0x41820014\n.long 0x7C090378\n.long 0x80090024\n.long 0x7C002000\n.long 0x4082FFF4\n.long 0x2C090000\n.long 0x41820010\n.long 0x80040024\n.long 0x90090024\n.long 0x4800000C\n.long 0x80040024\n.long 0x90030408\n.long 0x8003040C\n.long 0x7C002000\n.long 0x4C820020\n.long 0x38000000\n.long 0x9003040C\n.long 0x4E800020");
}
