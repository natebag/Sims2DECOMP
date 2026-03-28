// 0x801CF704 (124 bytes)
// O2TTarget::OnXKeyPressed(char *, char *)

class O2TTarget { public: void OnXKeyPressed(char *, char *); };

__attribute__((naked))
void O2TTarget::OnXKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x2C000000\n.long 0x40820058\n.long 0x8063009C\n.long 0x2C030000\n.long 0x41820010\n.long 0x2C030001\n.long 0x41820028\n.long 0x48000040\n.long 0x3C60803F\n.long 0x38800004\n.long 0x3863F810\n.long 0x4BFAA471\n.long 0x3C60803F\n.long 0x3863F81C\n.long 0x4BFA85C1\n.long 0x48000020\n.long 0x3C60803F\n.long 0x38800007\n.long 0x3863F810\n.long 0x4BFAA451\n.long 0x3C60803F\n.long 0x3863F81C\n.long 0x4BFA85A1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
