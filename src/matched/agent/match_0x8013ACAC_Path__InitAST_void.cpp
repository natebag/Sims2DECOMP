// 0x8013ACAC Path::InitAST(void) (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; lis 29,-32696; lwz 0,0x3c(31); addi 27,31,92; lwz 9,0x4c(31); addi 5,31,96; stw 0,0x40(31); addi 3,29,26792; stw 9,0x50(31); mr 4,27; bl _s8013ACAC_0; addi 28,31,60; lwz 4,0x5c(31); addi 3,29,26792; bl _s8013ACAC_1; lwz 11,0x0(31); mr 30,3; addi 3,29,26792; lwz 9,0xc(11); lwz 10,0x10(11); stw 9,0x14(30); stw 10,0x18(30); lwz 4,0x5c(31); bl _s8013ACAC_2; lis 9,-32706; li 0,-1; lfs f0,-11232(9); stw 0,0x1c(30); stfs f0,0x24(30); stfs f1,0x20(30); stfs f1,0x28(30); lwz 9,0x5c(31); stw 9,0x64(31); lwz 30,0x4(28); lwz 0,0xc(28); cmpw 30,0; beq 0f; stw 9,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 11f; 0:; lwz 0,0x3c(31); li 9,1; stw 9,0xc(1); addi 11,1,12; subf 0,0,30; addi 9,1,8; srawi 3,0,2; stw 3,0x8(1); cmplwi 3,1; bge 1f; mr 9,11; 1:; lwz 0,0x0(9); add. 0,3,0; beq 3f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 2f; mr 3,29; bl _s8013ACAC_3; mr 31,3; b 4f; 2:; mr 3,29; bl _s8013ACAC_4; mr 31,3; b 4f; 3:; li 31,0; li 29,0; 4:; lwz 4,0x0(28); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8013ACAC_5; add 0,3,30; b 6f; 5:; mr 0,31; 6:; lwz 9,0xc(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s8013ACAC_6; b 10f; 9:; bl _s8013ACAC_7; 10:; add 0,29,31; stw 31,0x0(28); stw 0,0xc(28); stw 30,0x4(28); 11:; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8013ACAC_0();
extern "C" void _s8013ACAC_1();
extern "C" void _s8013ACAC_2();
extern "C" void _s8013ACAC_3();
extern "C" void _s8013ACAC_4();
extern "C" void _s8013ACAC_5();
extern "C" void _s8013ACAC_6();
extern "C" void _s8013ACAC_7();
extern "C" void f_8013ACAC() {}
