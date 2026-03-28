// 0x801C70F0 (120 bytes)
// MMUTarget::EndPlayerNumberChooser(void)

class MMUTarget { public: void EndPlayerNumberChooser(void); };

__attribute__((naked))
void MMUTarget::EndPlayerNumberChooser(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800300A4\n.long 0x2C000002\n.long 0x40820024\n.long 0x3C60803F\n.long 0x38800000\n.long 0x3863F810\n.long 0x4BFB2A9D\n.long 0x3C60803F\n.long 0x38632D44\n.long 0x4BFB0BED\n.long 0x48000034\n.long 0x3D208047\n.long 0x3C80803F\n.long 0x81695EF8\n.long 0x3CA0803F\n.long 0x3884EB18\n.long 0x38A52D3C\n.long 0x812B0080\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
