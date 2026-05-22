// 0x80065400 EStream (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0xc(1); lwz 3,0x8(3); addi 3,3,820; bl _s80065400_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; mr 30,4; mr 29,6; mr. 28,5; beq 3f; li 0,0; addi 3,31,1488; stw 0,0x18(1); addi 5,1,24; bl _s80065400_1; cmpwi 3,0; bne 3f; stw 30,0x8(1); stw 28,0xc(1); extsh 30,29; sth 29,0x10(1); lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x118(9); lwz 9,0x11c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; 0:; lbz 0,-18451(13); or 0,30,0; b 2f; 1:; mr 0,30; 2:; sth 0,0x10(1); mr 3,31; addi 4,1,8; li 5,1; bl _s80065400_2; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s80065400_0();
extern "C" void _s80065400_1();
extern "C" void _s80065400_2();
extern "C" void f_80065400() {}
