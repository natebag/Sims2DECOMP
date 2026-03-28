// 0x8038D908 (104 bytes)
// GXGetTexObjAll

__attribute__((naked))
void GXGetTexObjAll() {
    asm volatile(".long 0x8003000C\n.long 0x540029B4\n.long 0x90040000\n.long 0x80030008\n.long 0x540405BE\n.long 0x38040001\n.long 0xB0050000\n.long 0x80030008\n.long 0x5404B5BE\n.long 0x38040001\n.long 0xB0060000\n.long 0x80030014\n.long 0x90070000\n.long 0x80030000\n.long 0x540007BE\n.long 0x90080000\n.long 0x80030000\n.long 0x5400F7BE\n.long 0x90090000\n.long 0x8803001F\n.long 0x540307FE\n.long 0x3803FFFF\n.long 0x7C000034\n.long 0x5400DE3E\n.long 0x980A0000\n.long 0x4E800020");
}
