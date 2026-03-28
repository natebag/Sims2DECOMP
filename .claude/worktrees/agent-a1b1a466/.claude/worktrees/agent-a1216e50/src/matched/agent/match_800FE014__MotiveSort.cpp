// 0x800FE014 (84 bytes)
// _MotiveSort(void *, void *)

__attribute__((naked))
void _MotiveSort(void *, void *) {
    asm volatile(".long 0x81630000\n.long 0x3D00803E\n.long 0x81240000\n.long 0x814D83B0\n.long 0x556B103A\n.long 0x5529103A\n.long 0xC988C090\n.long 0x7DA9542E\n.long 0x7C0B542E\n.long 0xEC006828\n.long 0xFDA00090\n.long 0xFC0D6000\n.long 0x4180001C\n.long 0x3D20803E\n.long 0xC809C098\n.long 0xFF8D0000\n.long 0x7C600026\n.long 0x5463F7FE\n.long 0x4E800020\n.long 0x3860FFFF\n.long 0x4E800020");
}
