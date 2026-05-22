// 0x801D7DA0 PCTTarget::enter_wallpaper_mode(PCTTarget::cCellInfo (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); lis 9,-32698; addi 11,1,8; addi 9,9,28960; li 0,4; stw 9,0x10(11); mr 29,3; stw 0,0x8(1); li 10,0; lwz 0,0x84(29); lis 9,-32739; stw 10,0x20(11); addi 9,9,7888; stw 10,0x14(11); mr 27,11; mr 28,5; mr. 31,4; stw 0,0xc(1); stw 9,0x14(1); stw 29,0x10(1); beq 0f; lwz 0,0x4(31); stw 0,0x24(1); lwz 9,0x14(31); stw 9,0x20(1); b 1f; 0:; lis 9,-32697; lwz 11,0x5ea4(9); lwz 10,0x0(11); lwz 0,0x0(10); stw 31,0x24(1); stw 0,0x20(1); 1:; lis 9,-32697; li 0,0; lwz 11,0x6188(9); stw 0,0x28(1); cmpwi 11,0; bne 2f; cmpwi 31,0; beq 4f; li 3,0; bl _s801D7DA0_0; mr 30,3; mr 3,31; bl _s801D7DA0_1; mr. 3,3; beq 2f; divw 0,30,3; b 3f; 2:; lis 0,32767; ori 0,0,65535; 3:; stw 0,0x28(1); 4:; cmpwi 28,0; li 0,1; beq 5f; li 0,0; 5:; stw 0,0x1c(1); beq 6f; lwz 3,0x214(29); li 4,4; bl _s801D7DA0_2; b 7f; 6:; lwz 3,0x214(29); li 4,7; bl _s801D7DA0_3; 7:; li 4,0; mr 3,29; bl _s801D7DA0_4; bl _s801D7DA0_5; lwz 31,0x4(27); mr 30,3; mr 4,31; bl _s801D7DA0_6; cmpwi 3,0; beq 9f; li 0,1; lbz 9,0x3c(30); slw 0,0,31; rlwinm 0,0,0,24,31; and. 29,9,0; bne 9f; or 0,0,9; li 3,36; stb 0,0x3c(30); bl _s801D7DA0_7; lis 9,-32698; li 0,4; addi 9,9,28960; stw 0,0x0(3); stw 29,0x20(3); rlwinm 4,31,3,0,28; stw 9,0x30(1); mr 11,3; stw 9,0x10(3); mr 10,27; stw 29,0x14(3); li 9,24; 8:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 8b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(30); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 9:; lis 9,-32698; li 3,1; addi 9,9,-10560; stw 9,0x10(27); lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"
extern "C" void _s801D7DA0_0();
extern "C" void _s801D7DA0_1();
extern "C" void _s801D7DA0_2();
extern "C" void _s801D7DA0_3();
extern "C" void _s801D7DA0_4();
extern "C" void _s801D7DA0_5();
extern "C" void _s801D7DA0_6();
extern "C" void _s801D7DA0_7();
extern "C" void f_801D7DA0() {}
