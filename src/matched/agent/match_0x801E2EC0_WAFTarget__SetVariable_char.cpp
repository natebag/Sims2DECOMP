// 0x801E2EC0 WAFTarget::SetVariable(char (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lbz 3,0x0(30); extsb 3,3; bl _s801E2EC0_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; lwz 3,-29256(13); mr 4,30; bl _s801E2EC0_1; mr. 3,3; bne 1f; li 0,1; stw 3,0x98(31); stw 0,0xa0(31); b 8f; 1:; lwz 3,-29244(13); mr 4,30; bl _s801E2EC0_2; mr. 29,3; bne 2f; lis 4,-32705; lwz 6,0x94(31); addi 4,4,25552; addi 3,31,592; li 5,0; bl _s801E2EC0_3; stw 29,0xa0(31); stw 29,0x98(31); b 8f; 2:; lwz 3,-29232(13); mr 4,30; bl _s801E2EC0_4; mr. 3,3; bne 3f; stw 3,0x8c(31); mr 3,31; bl _s801E2EC0_5; b 8f; 3:; lwz 3,-29220(13); mr 4,30; bl _s801E2EC0_6; mr. 28,3; bne 4f; addi 30,31,592; lwz 6,0x94(31); stw 28,0x8c(31); lis 4,-32705; addi 4,4,25580; li 5,0; mr 3,30; lis 29,-32705; bl _s801E2EC0_7; stw 28,0x88(31); mr 3,30; bl _s801E2EC0_8; lwz 5,0x94(31); mr 3,30; addi 4,29,25584; bl _s801E2EC0_9; li 4,0; mr 3,30; bl _s801E2EC0_10; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25500; mr 3,30; bl _s801E2EC0_11; mr 3,30; li 4,0; bl _s801E2EC0_12; lwz 5,0x94(31); addi 4,29,25584; mr 3,30; bl _s801E2EC0_13; li 4,0; mr 3,30; bl _s801E2EC0_14; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25520; mr 3,30; bl _s801E2EC0_15; mr 3,30; li 4,0; bl _s801E2EC0_16; mr 3,30; bl _s801E2EC0_17; b 8f; 4:; lwz 3,-29172(13); mr 4,30; bl _s801E2EC0_18; cmpwi 3,0; bne 5f; mr 3,31; bl _s801E2EC0_19; b 8f; 5:; lwz 3,-29184(13); mr 4,30; bl _s801E2EC0_20; cmpwi 3,0; bne 6f; mr 3,31; bl _s801E2EC0_21; b 8f; 6:; lwz 3,-29196(13); mr 4,30; bl _s801E2EC0_22; cmpwi 3,0; bne 7f; mr 3,31; bl _s801E2EC0_23; b 8f; 7:; lwz 3,-29208(13); mr 4,30; bl _s801E2EC0_24; cmpwi 3,0; bne 8f; li 0,1; stw 0,0x280(31); 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801E2EC0_0();
extern "C" void _s801E2EC0_1();
extern "C" void _s801E2EC0_2();
extern "C" void _s801E2EC0_3();
extern "C" void _s801E2EC0_4();
extern "C" void _s801E2EC0_5();
extern "C" void _s801E2EC0_6();
extern "C" void _s801E2EC0_7();
extern "C" void _s801E2EC0_8();
extern "C" void _s801E2EC0_9();
extern "C" void _s801E2EC0_10();
extern "C" void _s801E2EC0_11();
extern "C" void _s801E2EC0_12();
extern "C" void _s801E2EC0_13();
extern "C" void _s801E2EC0_14();
extern "C" void _s801E2EC0_15();
extern "C" void _s801E2EC0_16();
extern "C" void _s801E2EC0_17();
extern "C" void _s801E2EC0_18();
extern "C" void _s801E2EC0_19();
extern "C" void _s801E2EC0_20();
extern "C" void _s801E2EC0_21();
extern "C" void _s801E2EC0_22();
extern "C" void _s801E2EC0_23();
extern "C" void _s801E2EC0_24();
extern "C" void f_801E2EC0() {}
