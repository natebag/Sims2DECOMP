// 0x80069A8C (80 bytes)
// SAnimator2::getAnimDuration(ERAnim *)

class SAnimator2 { public: void getAnimDuration(ERAnim *); };

__attribute__((naked))
void SAnimator2::getAnimDuration(ERAnim *) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D20803D\n.long 0x7C842379\n.long 0xC0294C5C\n.long 0x41820038\n.long 0x81240018\n.long 0x3C004330\n.long 0x3D60803D\n.long 0x3929FFFF\n.long 0xC9AB4C60\n.long 0x6D298000\n.long 0xC1840064\n.long 0x9121000C\n.long 0x90010008\n.long 0xC8010008\n.long 0xFC006828\n.long 0xFC200018\n.long 0xEC216024\n.long 0x38210010\n.long 0x4E800020");
}
