// 0x800CE408 NeighborhoodImpl::SavePersistentData(cXPerson (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,4; mr 30,3; lwz 9,0x4(31); lwz 11,0x0(30); lha 3,0x1b0(9); lwz 9,0x1b4(9); addi 29,11,184; add 3,31,3; lha 0,0xb8(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; mr. 27,3; beq 3f; bl _s800CE408_0; li 29,0; stw 3,0x0(27); bl _s800CE408_1; mr 28,3; cmpw 29,28; bge 1f; addi 26,27,112; 0:; mr 3,29; bl _s800CE408_2; addi 29,29,1; lwz 9,0x4(31); mr 30,3; lwz 4,0x0(30); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x0(30); cmpw 29,28; add 0,0,0; sthx 3,26,0; blt 0b; 1:; mr 3,27; bl _s800CE408_3; mr. 11,3; beq 3f; lwz 9,0x0(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,1; bne 3f; lwz 9,0x4(31); lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,31,3; blrl; li 0,16; mr 10,3; mtspr 9,0; addi 8,27,272; addi 3,27,336; addi 11,10,64; li 9,0; 2:; lfsx f0,9,10; stfsx f0,9,8; addi 9,9,4; lfs f0,0x0(11); addi 11,11,4; stfs f0,0x0(3); addi 3,3,4; bdnz 2b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800CE408_0();
extern "C" void _s800CE408_1();
extern "C" void _s800CE408_2();
extern "C" void _s800CE408_3();
extern "C" void f_800CE408() {}
