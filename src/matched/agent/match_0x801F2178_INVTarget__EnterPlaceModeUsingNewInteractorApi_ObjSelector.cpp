// 0x801F2178 INVTarget::EnterPlaceModeUsingNewInteractorApi(ObjSelector (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 24,0x48(1); stw 0,0x6c(1); lis 30,-32697; mr 29,3; addi 30,30,23428; mr 31,4; addi 30,30,4; mr 28,5; mr 3,30; bl _s801F2178_0; lis 9,-32704; lfs f13,0x8(30); lfs f0,-25928(9); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; mr 3,29; bl _s801F2178_1; b 3f; 0:; addi 30,1,8; mr 3,29; bl _s801F2178_2; li 26,1; mr 3,31; li 25,6; bl _s801F2178_3; mr 24,30; lis 9,-32698; lwz 11,0x84(29); li 0,0; addi 27,9,29032; sth 0,0x20(30); lis 9,-32737; stw 0,0x14(30); addi 9,9,5628; stb 0,0x18(30); stw 0,0x1c(30); stw 27,0x10(30); stw 26,0x24(30); stb 28,0xcc(29); stb 28,0x20(1); stw 11,0xc(1); stw 9,0x14(1); stw 3,0x1c(1); stw 3,0xc8(29); stw 25,0x8(1); stw 29,0x10(1); bl _s801F2178_4; lwz 30,0x4(30); mr 28,3; mr 4,30; bl _s801F2178_5; cmpwi 3,0; beq 2f; slw 0,26,30; lbz 9,0x3c(28); rlwinm 0,0,0,24,31; and. 31,9,0; bne 2f; or 0,0,9; li 3,40; stb 0,0x3c(28); bl _s801F2178_6; li 0,0; sth 31,0x20(3); stb 0,0x18(3); rlwinm 4,30,3,0,28; stw 26,0x24(3); mr 11,3; stw 25,0x0(3); mr 10,24; stw 27,0x30(1); li 9,24; stw 27,0x10(3); stw 31,0x14(3); stw 31,0x1c(3); 1:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 1b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(28); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 2:; lis 9,-32698; mr 3,29; addi 9,9,-10560; li 4,0; stw 9,0x10(24); bl _s801F2178_7; mr 3,29; bl _s801F2178_8; 3:; lwz 0,0x6c(1); mtspr 8,0; lmw 24,0x48(1); addi 1,1,104"
extern "C" void _s801F2178_0();
extern "C" void _s801F2178_1();
extern "C" void _s801F2178_2();
extern "C" void _s801F2178_3();
extern "C" void _s801F2178_4();
extern "C" void _s801F2178_5();
extern "C" void _s801F2178_6();
extern "C" void _s801F2178_7();
extern "C" void _s801F2178_8();
extern "C" void f_801F2178() {}
