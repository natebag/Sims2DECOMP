// 0x8010FB78 __static_initialization_and_destruction_0 (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 12f; cmpwi 3,0; beq 2f; lis 9,-32696; li 30,1; addi 31,9,25472; 0:; mr 3,31; bl _s8010FB78_0; addi 31,31,88; cmpwi 30,0; addi 30,30,-1; bne 0b; li 9,1; 1:; cmpwi 9,0; addi 9,9,-1; bne 1b; lis 8,-32696; li 0,0; addi 6,8,25792; lis 10,-32696; addi 9,6,8; addi 7,10,25776; stw 0,0x4(9); addi 11,7,8; stw 0,0x64b0(10); stw 0,0x4(11); stw 0,0x64c0(8); stw 0,0x4(7); stw 0,0x4(6); b 12f; 2:; lis 9,-32696; addi 11,9,25792; lwz 9,0x64c0(9); lwz 0,0x4(11); cmpw 9,0; beq 4f; 3:; addi 9,9,72; cmpw 9,0; bne 3b; 4:; lwz 3,0x0(11); cmpwi 3,0; beq 6f; lwz 0,0xc(11); lis 9,14563; ori 9,9,36409; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,72; cmplwi 4,128; ble 5f; bl _s8010FB78_1; b 6f; 5:; bl _s8010FB78_2; 6:; lis 9,-32696; addi 11,9,25776; lwz 9,0x64b0(9); lwz 0,0x4(11); cmpw 9,0; beq 8f; 7:; addi 9,9,72; cmpw 9,0; bne 7b; 8:; lwz 3,0x0(11); cmpwi 3,0; beq 10f; lwz 0,0xc(11); lis 9,14563; ori 9,9,36409; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,72; cmplwi 4,128; ble 9f; bl _s8010FB78_3; b 10f; 9:; bl _s8010FB78_4; 10:; lis 9,-32696; addi 9,9,25472; cmpwi 9,0; beq 12f; addi 31,9,176; cmpw 31,9; beq 12f; mr 30,9; 11:; addi 31,31,-88; li 4,0; lwz 9,0x54(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; cmpw 31,30; bne 11b; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8010FB78_0();
extern "C" void _s8010FB78_1();
extern "C" void _s8010FB78_2();
extern "C" void _s8010FB78_3();
extern "C" void _s8010FB78_4();
extern "C" void f_8010FB78() {}
