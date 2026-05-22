// 0x801FC5D4 StartFire(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); lwz 3,-21508(13); lis 4,9417; ori 4,4,24473; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; mr. 26,3; bne 1f; b 4f; 0:; mr 3,30; mr 4,26; bl _s801FC5D4_0; li 3,1; b 5f; 1:; lwz 11,-21488(13); li 27,99; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 28,3; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; 2:; bl _s801FC5D4_1; mr 30,3; divw 0,30,28; mullw 0,0,28; subf 30,0,30; bl _s801FC5D4_2; mr 5,3; lwz 29,-21484(13); divw 9,5,31; mr 4,30; lwz 30,0x0(29); li 6,1; addi 3,1,8; lha 0,0x250(30); addi 30,30,592; add 29,29,0; mullw 9,9,31; subf 5,9,5; bl _s801FC5D4_3; lwz 0,0x4(30); addi 4,1,8; mr 3,29; mtspr 8,0; blrl; mr 30,3; li 4,2; addi 3,1,8; bl _s801FC5D4_4; lwz 11,-21484(13); mr 4,30; lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; mr. 30,3; beq 3f; lwz 9,0x4(30); lha 3,0x450(9); lwz 0,0x454(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0b; 3:; cmpwi 27,0; addi 27,27,-1; bne 2b; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s801FC5D4_0();
extern "C" void _s801FC5D4_1();
extern "C" void _s801FC5D4_2();
extern "C" void _s801FC5D4_3();
extern "C" void _s801FC5D4_4();
extern "C" void f_801FC5D4() {}
