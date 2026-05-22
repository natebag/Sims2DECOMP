// 0x8018CA90 LoadGameTarget::BackgroundPerformLoad(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 31,3; lwz 29,0x134(31); cmpwi 29,1; beq 3f; bgt 0f; cmpwi 29,0; beq 1f; b 8f; 0:; cmpwi 29,2; beq 5f; b 8f; 1:; addi 3,1,8; bl _s8018CA90_0; addi 3,1,8; li 4,16; bl _s8018CA90_1; lwz 30,-21480(13); addi 3,1,8; li 4,2; bl _s8018CA90_2; cmpwi 30,0; beq 2f; lwz 11,-22652(13); li 4,0; lwz 9,0x0(11); lwz 0,0x104(9); lha 3,0x100(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x118(31); lwz 3,-25136(13); lwz 4,0x190(9); bl _s8018CA90_3; lis 5,-32705; li 6,100; addi 5,5,-18528; li 4,-1; bl _s8018CA90_4; stw 3,0x148(31); li 0,1; stw 0,-26752(13); mr 3,31; bl _s8018CA90_5; lwz 9,0x134(31); addi 9,9,1; stw 9,0x134(31); 2:; li 0,1; stw 0,0x130(31); b 8f; 3:; addi 3,1,8; bl _s8018CA90_6; addi 3,1,8; li 4,16; bl _s8018CA90_7; lwz 30,-21480(13); addi 3,1,8; li 4,2; bl _s8018CA90_8; cmpwi 30,0; beq 4f; lwz 9,0x118(31); li 0,0; lwz 3,-25136(13); lwz 4,0x190(9); stw 0,-26752(13); bl _s8018CA90_9; lwz 4,0x148(31); bl _s8018CA90_10; lwz 10,-22652(13); lis 9,-32697; lwz 4,0x620c(9); lwz 11,0x0(10); lha 3,0x100(11); lwz 0,0x104(11); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x134(31); addi 9,9,1; stw 9,0x134(31); 4:; stw 29,0x130(31); b 8f; 5:; lwz 0,0x144(31); cmpwi 0,0; beq 6f; addi 3,31,132; bl _s8018CA90_11; li 0,1; stw 0,0x10c(31); b 7f; 6:; addi 3,31,132; bl _s8018CA90_12; li 0,5; li 9,1; stw 0,0x12c(31); stw 9,0x130(31); 7:; li 0,0; stw 0,0x134(31); 8:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s8018CA90_0();
extern "C" void _s8018CA90_1();
extern "C" void _s8018CA90_2();
extern "C" void _s8018CA90_3();
extern "C" void _s8018CA90_4();
extern "C" void _s8018CA90_5();
extern "C" void _s8018CA90_6();
extern "C" void _s8018CA90_7();
extern "C" void _s8018CA90_8();
extern "C" void _s8018CA90_9();
extern "C" void _s8018CA90_10();
extern "C" void _s8018CA90_11();
extern "C" void _s8018CA90_12();
extern "C" void f_8018CA90() {}
