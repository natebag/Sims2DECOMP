// 0x8023FCE0 CompletePCreadAsync (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); lis 9,-32700; lwz 0,-23472(9); cmpwi 0,1; bne 0f; bl _s8023FCE0_0; 0:; lis 9,-13312; lis 27,-32694; ori 9,9,26676; 1:; lwz 0,0x0(9); andi. 11,0,1; bne 1b; lis 30,-32694; lwz 9,-26488(30); addi 9,9,-1; stw 9,-26488(30); lwz 0,-26488(30); cmpwi 0,-1; beq 3f; lis 31,-32694; 2:; lwz 3,-26492(31); li 4,1024; bl _s8023FCE0_1; lwz 9,-26488(30); lwz 11,-26492(31); addi 9,9,-1; stw 9,-26488(30); addi 11,11,1024; stw 11,-26492(31); lwz 0,-26488(30); cmpwi 0,-1; bne 2b; 3:; lis 9,-32694; lwz 0,-26484(9); cmpwi 0,0; beq 4f; lis 9,-32694; lwz 4,-26484(27); lwz 3,-26492(9); bl _s8023FCE0_2; li 0,0; stw 0,-26484(27); 4:; lis 9,-13312; li 10,0; ori 9,9,26664; lis 11,-32694; stw 10,0x0(9); lwz 0,-26480(11); cmpwi 0,0; beq 9f; lis 29,-13312; lis 24,-32694; lis 25,-32694; li 28,0; ori 29,29,26664; lis 26,-32694; 5:; bl _s8023FCE0_3; lis 30,-32694; lwz 9,-26488(30); addi 9,9,-1; stw 9,-26488(30); lwz 0,-26488(30); cmpwi 0,-1; beq 7f; lis 31,-32694; 6:; lwz 3,-26492(31); li 4,1024; bl _s8023FCE0_4; lwz 9,-26488(30); lwz 11,-26492(31); addi 9,9,-1; stw 9,-26488(30); addi 11,11,1024; stw 11,-26492(31); lwz 0,-26488(30); cmpwi 0,-1; bne 6b; 7:; lwz 0,-26484(24); cmpwi 0,0; beq 8f; lwz 4,-26484(27); lwz 3,-26492(25); bl _s8023FCE0_5; stw 28,-26484(27); 8:; stw 28,0x0(29); lwz 0,-26480(26); cmpwi 0,0; bne 5b; 9:; bl _s8023FCE0_6; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s8023FCE0_0();
extern "C" void _s8023FCE0_1();
extern "C" void _s8023FCE0_2();
extern "C" void _s8023FCE0_3();
extern "C" void _s8023FCE0_4();
extern "C" void _s8023FCE0_5();
extern "C" void _s8023FCE0_6();
extern "C" void f_8023FCE0() {}
