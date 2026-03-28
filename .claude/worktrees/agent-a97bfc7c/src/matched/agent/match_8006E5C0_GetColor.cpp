// 0x8006E5C0 (116 bytes)
// GetColor(float, EVec4 &)

__attribute__((naked))
void GetColor(float, EVec4 &) {
    asm volatile(".long 0x3D20803D\n.long 0xC009516C\n.long 0xFC010000\n.long 0x4C620382\n.long 0x4D830020\n.long 0x40810024\n.long 0x3D20803D\n.long 0xC0095170\n.long 0xFC010000\n.long 0x4C620382\n.long 0x40830010\n.long 0x3C608047\n.long 0x386362C0\n.long 0x4E800020\n.long 0x3D20803D\n.long 0xC0095170\n.long 0xFC010000\n.long 0x40810024\n.long 0x3D20803D\n.long 0xC0095174\n.long 0xFC010000\n.long 0x4C620382\n.long 0x40830010\n.long 0x3C608047\n.long 0x386362A0\n.long 0x4E800020\n.long 0x3C608047\n.long 0x386362D0\n.long 0x4E800020");
}
