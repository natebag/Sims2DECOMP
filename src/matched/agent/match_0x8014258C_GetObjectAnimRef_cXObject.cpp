// 0x8014258C GetObjectAnimRef(cXObject (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,4; mr 30,3; lwz 9,0x4(28); mr 25,5; mr 31,6; mr 26,7; lha 3,0x1f8(9); li 27,0; lwz 0,0x1fc(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 27,1; 0:; cmpwi 31,0; mr 29,27; beq 1f; lwz 9,0x4(28); lha 3,0xe8(9); lwz 0,0xec(9); add 3,28,3; mtspr 8,0; blrl; bl _s8014258C_0; cmpw 3,30; bne 1f; lwz 9,0x4(28); lha 3,0xe8(9); lwz 0,0xec(9); add 3,28,3; mtspr 8,0; blrl; bl _s8014258C_1; mr. 31,3; beq 1f; lwz 9,0x4(31); lha 3,0x318(9); lwz 0,0x31c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,2; bne 1f; lwz 3,0x0(31); li 4,2; bl _s8014258C_2; mr. 11,3; beq 1f; lwz 9,0x4(11); li 29,0; lha 3,0x1f8(9); lwz 0,0x1fc(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 29,1; 1:; cmpwi 27,0; beq 3f; cmpwi 29,0; beq 2f; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s8014258C_3; b 5f; 2:; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s8014258C_4; b 5f; 3:; cmpwi 29,0; beq 4f; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s8014258C_5; b 5f; 4:; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s8014258C_6; 5:; mr 31,3; li 0,0; cmpwi 31,0; stw 0,0x0(26); beq 6f; lwz 9,0x0(31); mr 4,25; lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; stw 3,0x0(26); 6:; lwz 0,0x0(26); cmpwi 0,0; beq 7f; li 3,0; li 4,1; b 8f; 7:; mr 3,30; mr 4,28; mr 5,31; mr 6,25; bl _s8014258C_7; li 3,-1; li 4,-1; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8014258C_0();
extern "C" void _s8014258C_1();
extern "C" void _s8014258C_2();
extern "C" void _s8014258C_3();
extern "C" void _s8014258C_4();
extern "C" void _s8014258C_5();
extern "C" void _s8014258C_6();
extern "C" void _s8014258C_7();
extern "C" void f_8014258C() {}
