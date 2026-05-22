// 0x801F76A8 INVTarget::EnterWallBuildMode(InteractorModule::WallData (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); lis 9,-32698; addi 10,1,8; addi 9,9,28984; li 0,3; stw 9,0x10(10); mr 31,3; stw 0,0x8(1); li 9,0; lwz 0,0x84(31); lis 11,-32737; stw 9,0x24(10); addi 11,11,6516; stw 9,0x14(10); mr 28,10; stw 9,0x18(10); mr 30,5; mr. 4,4; stw 0,0xc(1); stw 11,0x14(1); stw 31,0x10(1); bne 0f; li 0,-1; stw 4,0x1c(1); stw 0,0x28(1); b 1f; 0:; li 0,1; stw 0,0x1c(1); lwz 9,0x0(4); lwz 10,0x4(4); stw 9,0x24(1); stw 10,0x28(1); 1:; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 2f; lwz 0,-21088(13); mr 3,31; stw 0,0x2c(1); bl _s801F76A8_0; b 6f; 2:; cmpwi 4,0; beq 3f; lwz 5,0x4(4); lwz 3,0x90(31); li 4,2; bl _s801F76A8_1; b 4f; 3:; lwz 3,0x90(31); li 4,4; li 5,-1; bl _s801F76A8_2; 4:; cmpwi 3,0; beq 5f; bl _s801F76A8_3; 5:; stw 3,0x2c(1); 6:; cmpwi 30,1; bne 7f; stw 30,0x20(1); b 8f; 7:; li 0,0; stw 0,0x20(1); 8:; li 4,0; mr 3,31; bl _s801F76A8_4; lwz 0,0x2c(1); li 9,1; stw 9,0x32e4(31); mr 3,31; stw 0,0x32e8(31); bl _s801F76A8_5; lwz 0,0x0(31); lwz 4,-28692(13); cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lis 5,-8489; lwz 6,0x7c(31); ori 5,5,45095; li 7,0; bl _s801F76A8_6; 9:; bl _s801F76A8_7; lwz 31,0x4(28); mr 29,3; mr 4,31; bl _s801F76A8_8; cmpwi 3,0; beq 11f; li 0,1; lbz 9,0x3c(29); slw 0,0,31; rlwinm 0,0,0,24,31; and. 30,9,0; bne 11f; or 0,0,9; li 3,40; stb 0,0x3c(29); bl _s801F76A8_9; lis 9,-32698; li 0,3; addi 9,9,28984; stw 0,0x0(3); stw 30,0x24(3); rlwinm 4,31,3,0,28; stw 9,0x30(1); mr 11,3; stw 9,0x10(3); mr 10,28; stw 30,0x14(3); li 9,24; stw 30,0x18(3); 10:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 10b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(29); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 11:; lis 9,-32698; addi 9,9,-10560; stw 9,0x10(28); lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s801F76A8_0();
extern "C" void _s801F76A8_1();
extern "C" void _s801F76A8_2();
extern "C" void _s801F76A8_3();
extern "C" void _s801F76A8_4();
extern "C" void _s801F76A8_5();
extern "C" void _s801F76A8_6();
extern "C" void _s801F76A8_7();
extern "C" void _s801F76A8_8();
extern "C" void _s801F76A8_9();
extern "C" void f_801F76A8() {}
