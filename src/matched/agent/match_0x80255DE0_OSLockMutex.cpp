// 0x80255DE0 OSLockMutex (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); mr 28,3; bl _s80255DE0_0; mr 29,3; bl _s80255DE0_1; addi 30,3,0; li 31,0; 0:; lwz 0,0x8(28); cmplwi 0,0; bne 3f; stw 30,0x8(28); lwz 3,0xc(28); addi 0,3,1; stw 0,0xc(28); lwz 3,0x2f8(30); cmplwi 3,0; bne 1f; stw 28,0x2f4(30); b 2f; 1:; stw 28,0x10(3); 2:; stw 3,0x14(28); li 0,0; stw 0,0x10(28); stw 28,0x2f8(30); b 5f; 3:; cmplw 0,30; bne 4f; lwz 3,0xc(28); addi 0,3,1; stw 0,0xc(28); b 5f; 4:; stw 28,0x2f0(30); lwz 3,0x8(28); lwz 4,0x2d0(30); bl _s80255DE0_2; mr 3,28; bl _s80255DE0_3; stw 31,0x2f0(30); b 0b; 5:; mr 3,29; bl _s80255DE0_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80255DE0_0();
extern "C" void _s80255DE0_1();
extern "C" void _s80255DE0_2();
extern "C" void _s80255DE0_3();
extern "C" void _s80255DE0_4();
extern "C" void f_80255DE0() {}
