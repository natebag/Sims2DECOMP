// 0x803B73A0 (76 bytes)
// G2DDummyPrintf(char *,...)

__attribute__((naked))
void G2DDummyPrintf(char *,...) {
    asm volatile(".long 0x9421FF90\n.long 0x9081000C\n.long 0x90A10010\n.long 0x90C10014\n.long 0x90E10018\n.long 0x9101001C\n.long 0x91210020\n.long 0x91410024\n.long 0x40860024\n.long 0xD8210028\n.long 0xD8410030\n.long 0xD8610038\n.long 0xD8810040\n.long 0xD8A10048\n.long 0xD8C10050\n.long 0xD8E10058\n.long 0xD9010060\n.long 0x38210070\n.long 0x4E800020");
}
