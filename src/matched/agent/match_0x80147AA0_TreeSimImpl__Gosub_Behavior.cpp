// 0x80147AA0 TreeSimImpl::Gosub(Behavior (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 26,3; mr 31,4; addi 30,26,12; mr 29,5; mr 28,6; mr 3,30; bl _s80147AA0_0; addi 4,3,-1; mr 3,30; bl _s80147AA0_1; mr 30,3; cmpwi 31,0; bne 1f; lwz 31,0x10(30); cmpwi 31,0; bne 1f; 0:; li 3,0; b 11f; 1:; li 27,0; mr 3,31; stw 27,0x20(1); mr 4,28; addi 5,1,32; li 6,0; bl _s80147AA0_2; cmpwi 3,0; bne 2f; lwz 11,0x20(1); cmpwi 11,0; beq 0b; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 0b; 2:; stw 31,0x18(1); mr 4,28; stw 27,0x10(1); addi 3,1,8; bl _s80147AA0_3; cmpwi 30,0; beq 3f; lhz 0,0x4(30); sth 0,0xc(1); b 4f; 3:; sth 30,0xc(1); 4:; cmpwi 29,0; bne 5f; lwz 29,0x30(26); 5:; lwz 3,0x20(1); bl _s80147AA0_4; cmpwi 3,4; bne 6f; lhz 0,0x0(29); lwz 3,0x20(1); sth 0,0xa(1); bl _s80147AA0_5; lha 0,0xa(1); cmpw 0,3; blt 7f; lwz 3,0x20(1); bl _s80147AA0_6; addi 3,3,-1; sth 3,0xa(1); b 7f; 6:; li 0,0; sth 0,0xa(1); 7:; lha 0,0xa(1); cmpwi 0,0; blt 8f; lwz 3,0x20(1); bl _s80147AA0_7; lha 0,0xa(1); cmpw 0,3; blt 9f; 8:; lwz 11,0x20(1); cmpwi 11,0; beq 0b; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 0b; 9:; lwz 3,0x20(1); bl _s80147AA0_8; stb 3,0xe(1); lwz 3,0x20(1); bl _s80147AA0_9; stb 3,0xf(1); mr 5,29; addi 3,26,12; addi 4,1,8; bl _s80147AA0_10; lwz 11,0x20(1); cmpwi 11,0; beq 10f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 10:; li 3,1; 11:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s80147AA0_0();
extern "C" void _s80147AA0_1();
extern "C" void _s80147AA0_2();
extern "C" void _s80147AA0_3();
extern "C" void _s80147AA0_4();
extern "C" void _s80147AA0_5();
extern "C" void _s80147AA0_6();
extern "C" void _s80147AA0_7();
extern "C" void _s80147AA0_8();
extern "C" void _s80147AA0_9();
extern "C" void _s80147AA0_10();
extern "C" void f_80147AA0() {}
