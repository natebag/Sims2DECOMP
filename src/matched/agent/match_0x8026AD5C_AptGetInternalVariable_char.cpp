// 0x8026AD5C AptGetInternalVariable(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,4; addi 30,1,8; mr 4,3; lis 28,-32704; mr 3,30; lis 29,-32704; bl _s8026AD5C_0; li 3,0; bl _s8026AD5C_1; mr 4,3; li 9,0; lis 3,-32694; li 7,1; li 8,1; mr 6,30; li 5,0; addi 3,3,-16032; bl _s8026AD5C_2; mr 30,3; addi 5,29,3504; lwz 9,0x8(30); li 6,1407; addi 4,28,3584; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; mr 4,27; bl _s8026AD5C_3; lwz 9,0x8(30); addi 4,28,3584; addi 5,29,3504; li 6,1409; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026AD5C_4; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8026AD5C_0();
extern "C" void _s8026AD5C_1();
extern "C" void _s8026AD5C_2();
extern "C" void _s8026AD5C_3();
extern "C" void _s8026AD5C_4();
extern "C" void f_8026AD5C() {}
