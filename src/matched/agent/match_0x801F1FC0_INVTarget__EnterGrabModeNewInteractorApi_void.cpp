// 0x801F1FC0 INVTarget::EnterGrabModeNewInteractorApi(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f31,0x68(1); stmw 25,0x4c(1); stw 0,0x74(1); mr 28,3; addi 30,1,8; li 26,2; bl _s801F1FC0_0; mr 25,30; lis 11,-32698; lis 9,-32704; lfs f31,-25932(9); addi 27,11,29056; stw 27,0x10(30); addi 9,1,36; stfs f31,0x4(9); li 10,0; stfs f31,0x8(9); li 11,0; stfs f31,0x24(1); lis 9,-32737; stw 26,0x8(1); addi 9,9,7644; lwz 0,0x84(28); sth 10,0x14(30); stw 11,0x18(30); stw 0,0xc(1); stw 9,0x14(1); stw 28,0x10(1); bl _s801F1FC0_1; lwz 30,0x4(30); mr 31,3; mr 4,30; bl _s801F1FC0_2; cmpwi 3,0; beq 1f; li 0,1; lbz 9,0x3c(31); slw 0,0,30; rlwinm 0,0,0,24,31; and. 29,9,0; bne 1f; or 0,0,9; li 3,40; stb 0,0x3c(31); bl _s801F1FC0_3; stw 27,0x10(3); addi 9,3,28; stfs f31,0x4(9); rlwinm 4,30,3,0,28; stfs f31,0x8(9); mr 11,3; stfs f31,0x1c(3); mr 10,25; lwz 0,0x10(3); li 9,24; stw 26,0x0(3); stw 29,0x18(3); stw 0,0x30(1); sth 29,0x14(3); 0:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(31); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 1:; mr 3,28; li 4,0; bl _s801F1FC0_4; mr 3,28; bl _s801F1FC0_5; lis 9,-32698; addi 9,9,-10560; stw 9,0x10(25); lwz 0,0x74(1); mtspr 8,0; lmw 25,0x4c(1); lfd f31,0x68(1); addi 1,1,112"
extern "C" void _s801F1FC0_0();
extern "C" void _s801F1FC0_1();
extern "C" void _s801F1FC0_2();
extern "C" void _s801F1FC0_3();
extern "C" void _s801F1FC0_4();
extern "C" void _s801F1FC0_5();
extern "C" void f_801F1FC0() {}
