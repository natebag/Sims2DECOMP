// 0x801980E0 CASGeneticsTarget::ClearParentTexture(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); cmplwi 4,1; bgt 0f; rlwinm 29,4,2,0,29; addi 30,3,788; lwzx 0,30,29; cmpwi 0,0; beq 0f; lis 3,-32692; lis 4,1077; addi 3,3,-7364; ori 4,4,15191; li 5,0; li 6,0; bl _s801980E0_0; mr. 31,3; beq 0f; lwzx 3,30,29; mr 4,31; li 5,0; bl _s801980E0_1; mr 3,31; bl _s801980E0_2; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801980E0_0();
extern "C" void _s801980E0_1();
extern "C" void _s801980E0_2();
extern "C" void f_801980E0() {}
