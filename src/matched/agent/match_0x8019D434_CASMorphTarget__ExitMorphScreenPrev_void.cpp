// 0x8019D434 CASMorphTarget::ExitMorphScreenPrev(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 27,0x13c(1); stw 0,0x154(1); mr 10,3; lwz 0,0x1c0(10); cmpwi 0,0; beq 1f; lis 9,-32698; addi 11,1,8; addi 9,9,24616; li 30,0; stw 9,0x4(11); addi 29,11,8; mr 27,11; addi 28,10,156; stw 30,0x1c0(10); mr 3,29; lwz 31,0x84(10); bl _s8019D434_0; stw 30,0x8(1); li 9,288; 0:; lwz 0,0x0(28); addic. 9,9,-24; stw 0,0x0(29); lwz 0,0x4(28); stw 0,0x4(29); lwz 0,0x8(28); stw 0,0x8(29); lwz 0,0xc(28); stw 0,0xc(29); lwz 0,0x10(28); stw 0,0x10(29); lwz 0,0x14(28); addi 28,28,24; stw 0,0x14(29); addi 29,29,24; bne 0b; lwz 0,0x0(28); mr 3,31; addi 4,1,8; stw 0,0x0(29); bl _s8019D434_1; lis 9,-32698; mr 3,27; addi 9,9,24616; li 4,2; stw 9,0x4(27); bl _s8019D434_2; 1:; lwz 0,0x154(1); mtspr 8,0; lmw 27,0x13c(1); addi 1,1,336"
extern "C" void _s8019D434_0();
extern "C" void _s8019D434_1();
extern "C" void _s8019D434_2();
extern "C" void f_8019D434() {}
