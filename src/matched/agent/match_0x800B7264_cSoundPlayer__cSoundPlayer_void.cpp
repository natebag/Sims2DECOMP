// 0x800B7264 cSoundPlayer::cSoundPlayer(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 30,3; li 29,0; addi 28,30,24; li 3,20; stw 29,0x4(28); bl _s800B7264_0; mr 9,3; stw 9,0x0(9); mr 3,30; stw 9,0x4(9); stw 9,0x4(28); stw 29,0x10(30); stw 29,0x0(30); stw 29,0x4(30); stw 29,0x8(30); stw 29,0xc(30); stw 29,0x18(1); lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s800B7264_0();
extern "C" void f_800B7264() {}
