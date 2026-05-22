// 0x8015ACA0 ResourceBehaviorTree::LoadFromIndex(unsigned (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 0,0x58(31); addi 3,31,88; mr 30,5; cmpw 28,0; bne 0f; lwz 0,0x60(31); cmpwi 0,0; beq 0f; rlwinm 4,30,0,16,31; bl _s8015ACA0_0; lwz 3,0x60(31); mr 4,30; bl _s8015ACA0_1; cmpwi 3,0; stw 3,0x54(31); beq 0f; li 3,1; b 5f; 0:; lwz 0,0x8(31); cmpwi 0,0; beq 2f; lwz 3,0x60(31); cmpwi 3,0; beq 1f; bl _s8015ACA0_2; li 0,0; stw 0,0x60(31); 1:; li 0,0; stw 0,0x8(31); stw 0,0x60(31); 2:; lwz 11,-21508(13); mr 4,28; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x8(3); li 5,0; lis 3,-32693; li 6,0; lwz 4,0xc(9); addi 3,3,27900; bl _s8015ACA0_3; stw 3,0x60(31); cmpwi 3,0; beq 3f; mr 4,30; bl _s8015ACA0_4; addi 30,31,88; mr 29,3; lwz 3,0x60(31); mr 4,29; bl _s8015ACA0_5; stw 3,0x54(31); mr 4,28; mr 3,30; bl _s8015ACA0_6; mr 3,30; rlwinm 4,29,0,16,31; bl _s8015ACA0_7; li 0,1; stw 0,0x8(31); b 4f; 3:; stw 3,0x54(31); 4:; lwz 0,0x54(31); li 3,1; cmpwi 0,0; bne 5f; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015ACA0_0();
extern "C" void _s8015ACA0_1();
extern "C" void _s8015ACA0_2();
extern "C" void _s8015ACA0_3();
extern "C" void _s8015ACA0_4();
extern "C" void _s8015ACA0_5();
extern "C" void _s8015ACA0_6();
extern "C" void _s8015ACA0_7();
extern "C" void f_8015ACA0() {}
