// 0x8032B070 (100 bytes)
// sort3IntPtrs(int **)

__attribute__((naked))
void sort3IntPtrs(int **) {
    asm volatile(".long 0x81630000\n.long 0x81430004\n.long 0x812B0000\n.long 0x800A0000\n.long 0x7C090000\n.long 0x4081000C\n.long 0x91630004\n.long 0x91430000\n.long 0x81630004\n.long 0x81430008\n.long 0x812B0000\n.long 0x800A0000\n.long 0x7C090000\n.long 0x4081000C\n.long 0x91630008\n.long 0x91430004\n.long 0x81430000\n.long 0x81630004\n.long 0x812A0000\n.long 0x800B0000\n.long 0x7C090000\n.long 0x4C810020\n.long 0x91630000\n.long 0x91430004\n.long 0x4E800020");
}
