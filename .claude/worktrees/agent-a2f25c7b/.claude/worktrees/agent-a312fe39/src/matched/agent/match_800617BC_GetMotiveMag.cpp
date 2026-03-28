// 0x800617BC (72 bytes)
// GetMotiveMag(float)

__attribute__((naked))
void GetMotiveMag(float) {
    asm volatile(".long 0x3D20803D\n.long 0x3D60803D\n.long 0xC009481C\n.long 0x3D40803D\n.long 0xC1AB4820\n.long 0xEC21002A\n.long 0xEC216824\n.long 0xC00A4824\n.long 0xFC010000\n.long 0x4180001C\n.long 0x3D20803D\n.long 0xFC000890\n.long 0xC1A94828\n.long 0xFC016800\n.long 0x40810008\n.long 0xFC006890\n.long 0xFC200090\n.long 0x4E800020");
}
