// 0x8006A494 (116 bytes)
// SAnimator2::getDeltaDirFromDesiredDir(float)

class SAnimator2 { public: void getDeltaDirFromDesiredDir(float); };

__attribute__((naked))
void SAnimator2::getDeltaDirFromDesiredDir(float) {
    asm volatile(".long 0xC0030030\n.long 0x3D20803D\n.long 0xC1A94CDC\n.long 0xEC210028\n.long 0xFC016800\n.long 0x40810018\n.long 0x3D20803D\n.long 0xC0094CD8\n.long 0xEC210028\n.long 0xFC016800\n.long 0x4181FFF8\n.long 0x3D20803D\n.long 0xC0094CE0\n.long 0xFC010000\n.long 0x4080001C\n.long 0x3D20803D\n.long 0xFDA00090\n.long 0xC0094CD8\n.long 0xEC21002A\n.long 0xFC016800\n.long 0x4180FFF8\n.long 0x3D20803D\n.long 0xFDA00A10\n.long 0xC0094CE4\n.long 0xFC0D0000\n.long 0x4C800020\n.long 0x3D20803D\n.long 0xC0294CE8\n.long 0x4E800020");
}
