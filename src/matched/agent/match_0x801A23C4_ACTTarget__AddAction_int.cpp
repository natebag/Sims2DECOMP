// 0x801A23C4 ACTTarget::AddAction(int, (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 22,0x20(1); stw 0,0x4c(1); mr 31,5; mr 28,3; lwz 0,0x38(31); mr 27,4; mr 24,6; mr 22,7; cmpwi 0,0; mr 25,8; mr 23,9; li 0,1; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 8f; lwz 30,0xdc(28); lis 29,-32697; addi 29,29,24012; mr 3,31; rlwinm 30,30,2,0,29; addi 29,29,188; bl _s801A23C4_0; lwzx 0,29,30; cmpw 0,3; bne 8f; lwz 0,0xdc(28); cmpw 0,27; bne 8f; addi 9,28,1616; li 29,0; lwz 11,0x4(9); lwz 0,0x0(11); stw 0,0x8(1); mr 26,9; b 3f; 1:; lwz 9,0x8(1); lwz 11,0x38(31); lwz 30,0x8(9); lwz 0,0x8(30); cmpw 0,11; bne 2f; mr 3,31; bl _s801A23C4_1; lwz 0,0x0(30); cmpw 0,3; bne 2f; li 29,1; 2:; lwz 9,0x8(1); stw 9,0x18(1); lwz 0,0x0(9); stw 9,0x10(1); stw 0,0x8(1); 3:; lwz 9,0x4(26); li 10,0; lwz 0,0x8(1); li 11,1; stw 9,0x10(1); cmpw 0,9; bne 4f; li 11,0; 4:; cmpwi 11,0; beq 5f; cmpwi 29,0; bne 5f; li 10,1; 5:; cmpwi 10,0; bne 1b; cmpwi 29,0; bne 8f; lwz 3,0xe4(28); cmpwi 3,0; beq 7f; lwz 9,0x38(31); 6:; lwz 0,0x38(3); cmpw 0,9; beq 8f; lwz 3,0x44(3); cmpwi 3,0; bne 6b; 7:; li 3,32; bl _s801A23C4_2; mr 30,3; lwz 27,0x38(31); mr 3,31; addi 29,30,12; bl _s801A23C4_3; lis 9,-32698; mr 28,3; addi 9,9,31136; mr 3,29; stw 9,0x1c(30); bl _s801A23C4_4; mr 4,24; stw 31,0x4(30); stw 27,0x8(30); mr 3,29; stw 28,0x0(30); bl _s801A23C4_5; lwz 0,0x4(26); li 3,12; stw 22,0x10(30); stw 23,0x18(30); stw 0,0x10(1); stw 25,0x14(30); bl _s801A23C4_6; stw 30,0x8(3); cmpwi 25,0; lwz 9,0x10(1); lwz 11,0x4(9); stw 9,0x0(3); stw 11,0x4(3); stw 3,0x0(11); stw 3,0x4(9); stw 3,0x8(1); beq 8f; mr 3,25; bl _s801A23C4_7; 8:; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x20(1); addi 1,1,72"
extern "C" void _s801A23C4_0();
extern "C" void _s801A23C4_1();
extern "C" void _s801A23C4_2();
extern "C" void _s801A23C4_3();
extern "C" void _s801A23C4_4();
extern "C" void _s801A23C4_5();
extern "C" void _s801A23C4_6();
extern "C" void _s801A23C4_7();
extern "C" void f_801A23C4() {}
