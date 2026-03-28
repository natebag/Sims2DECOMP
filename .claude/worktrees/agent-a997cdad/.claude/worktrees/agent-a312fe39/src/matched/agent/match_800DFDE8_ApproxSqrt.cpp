// 0x800DFDE8 (80 bytes)
// ApproxSqrt(float)

__attribute__((naked))
void ApproxSqrt(float) {
    asm volatile(".long 0xFD600890\n.long 0x3D20803E\n.long 0xC029AEC4\n.long 0xFC0B0800\n.long 0x4C620382\n.long 0x4D830020\n.long 0x3D20803E\n.long 0x3D40803E\n.long 0xC029AEC8\n.long 0x3D60803E\n.long 0xC1AAAECC\n.long 0xC18BAED0\n.long 0xEC2B687A\n.long 0xEC0B0824\n.long 0xEC21002A\n.long 0xEC210332\n.long 0xEC0B0824\n.long 0xEC21002A\n.long 0xEC210332\n.long 0x4E800020");
}
