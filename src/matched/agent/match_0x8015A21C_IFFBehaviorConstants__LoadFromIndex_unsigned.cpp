// 0x8015A21C IFFBehaviorConstants::LoadFromIndex(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 29,3; mr 28,4; mr 30,5; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lis 4,16963; lwz 9,0xc(31); extsh 5,30; ori 4,4,20302; li 6,0; lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; mr. 5,3; li 3,0; beq 0f; mr 4,31; mr 3,29; bl _s8015A21C_0; addi 3,29,8; mr 4,28; bl _s8015A21C_1; li 3,1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015A21C_0();
extern "C" void _s8015A21C_1();
extern "C" void f_8015A21C() {}
