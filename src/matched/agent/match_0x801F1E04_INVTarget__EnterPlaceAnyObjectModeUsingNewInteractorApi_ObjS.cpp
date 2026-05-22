// 0x801F1E04 INVTarget::EnterPlaceAnyObjectModeUsingNewInteractorApi(ObjSelector (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 23,0x4c(1); stw 0,0x74(1); mr 31,3; addi 30,1,8; mr 29,4; bl _s801F1E04_0; li 26,1; mr 3,29; li 24,0; bl _s801F1E04_1; li 25,6; lis 9,-32698; lwz 10,0x84(31); li 0,0; addi 27,9,29032; sth 0,0x20(30); li 11,0; stw 0,0x14(30); lis 9,-32737; stb 0,0x18(30); addi 9,9,5628; stw 0,0x1c(30); mr 23,30; stw 27,0x10(30); stw 26,0x24(30); stb 11,0xcc(31); stw 10,0xc(1); stw 9,0x14(1); stw 3,0x1c(1); stw 3,0xc8(31); stw 25,0x8(1); stw 31,0x10(1); stb 24,0x20(1); bl _s801F1E04_2; lwz 30,0x4(30); mr 28,3; mr 4,30; bl _s801F1E04_3; cmpwi 3,0; beq 1f; slw 0,26,30; lbz 9,0x3c(28); rlwinm 0,0,0,24,31; and. 29,9,0; bne 1f; or 0,0,9; li 3,40; stb 0,0x3c(28); bl _s801F1E04_4; stb 24,0x18(3); rlwinm 4,30,3,0,28; sth 29,0x20(3); mr 11,3; stw 26,0x24(3); mr 10,23; stw 25,0x0(3); li 9,24; stw 27,0x30(1); stw 27,0x10(3); stw 29,0x14(3); stw 29,0x1c(3); 0:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(28); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 1:; lis 9,-32698; mr 3,31; addi 9,9,-10560; li 4,0; stw 9,0x10(23); bl _s801F1E04_5; mr 3,31; bl _s801F1E04_6; lwz 0,0x74(1); mtspr 8,0; lmw 23,0x4c(1); addi 1,1,112"
extern "C" void _s801F1E04_0();
extern "C" void _s801F1E04_1();
extern "C" void _s801F1E04_2();
extern "C" void _s801F1E04_3();
extern "C" void _s801F1E04_4();
extern "C" void _s801F1E04_5();
extern "C" void _s801F1E04_6();
extern "C" void f_801F1E04() {}
