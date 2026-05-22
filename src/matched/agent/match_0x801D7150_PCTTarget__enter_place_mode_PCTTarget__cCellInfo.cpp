// 0x801D7150 PCTTarget::enter_place_mode(PCTTarget::cCellInfo (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 23,0x4c(1); stw 0,0x74(1); mr 28,3; mr 31,4; lwz 0,0x90(28); cmpwi 0,2; beq 9f; cmpwi 31,0; li 3,0; beq 10f; lwz 3,0x214(28); cmpwi 3,0; beq 0f; bl _s801D7150_0; lwz 3,0x214(28); li 4,0; bl _s801D7150_1; 0:; lis 3,14155; ori 3,3,56554; bl _s801D7150_2; lwz 29,0x0(31); cmpwi 29,2; beq 6f; bgt 1f; cmpwi 29,1; beq 2f; b 9f; 1:; cmpwi 29,3; beq 7f; cmpwi 29,4; beq 8f; b 9f; 2:; lwz 3,0x214(28); cmpwi 3,0; beq 3f; li 4,0; bl _s801D7150_3; 3:; lwz 11,0x84(28); addi 30,1,8; li 0,0; lis 9,-32698; sth 0,0x20(30); addi 26,9,29032; lis 9,-32739; li 24,6; lwz 3,0x14(31); addi 9,9,7792; stw 0,0x14(30); li 25,0; stb 0,0x18(30); mr 23,30; stw 0,0x1c(30); stw 26,0x10(30); stw 29,0x24(30); stw 11,0xc(1); stw 9,0x14(1); stw 24,0x8(1); stw 28,0x10(1); bl _s801D7150_4; stw 3,0x1c(1); stb 25,0x20(1); bl _s801D7150_5; lwz 30,0x4(30); mr 27,3; mr 4,30; bl _s801D7150_6; cmpwi 3,0; beq 5f; slw 0,29,30; lbz 9,0x3c(27); rlwinm 0,0,0,24,31; and. 31,9,0; bne 5f; or 0,0,9; li 3,40; stb 0,0x3c(27); bl _s801D7150_7; stb 25,0x18(3); rlwinm 4,30,3,0,28; sth 31,0x20(3); mr 11,3; stw 29,0x24(3); mr 10,23; stw 24,0x0(3); li 9,24; stw 26,0x30(1); stw 26,0x10(3); stw 31,0x14(3); stw 31,0x1c(3); 4:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 4b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(27); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 5:; mr 3,28; li 4,0; bl _s801D7150_8; lis 9,-32698; li 3,1; addi 9,9,-10560; stw 9,0x10(23); b 10f; 6:; mr 3,28; mr 4,31; li 5,1; bl _s801D7150_9; b 10f; 7:; mr 3,28; mr 4,31; li 5,1; bl _s801D7150_10; b 10f; 8:; mr 3,28; mr 4,31; li 5,1; bl _s801D7150_11; b 10f; 9:; li 3,0; 10:; lwz 0,0x74(1); mtspr 8,0; lmw 23,0x4c(1); addi 1,1,112"
extern "C" void _s801D7150_0();
extern "C" void _s801D7150_1();
extern "C" void _s801D7150_2();
extern "C" void _s801D7150_3();
extern "C" void _s801D7150_4();
extern "C" void _s801D7150_5();
extern "C" void _s801D7150_6();
extern "C" void _s801D7150_7();
extern "C" void _s801D7150_8();
extern "C" void _s801D7150_9();
extern "C" void _s801D7150_10();
extern "C" void _s801D7150_11();
extern "C" void f_801D7150() {}
