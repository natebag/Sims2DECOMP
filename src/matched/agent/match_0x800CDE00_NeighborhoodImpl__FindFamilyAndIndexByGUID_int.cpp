// 0x800CDE00 NeighborhoodImpl::FindFamilyAndIndexByGUID(int, (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 9,0x0(3); mr 29,4; mr 26,5; lha 0,0xc0(9); mr 25,6; lwz 9,0xc4(9); li 27,0; add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 2f; bl _s800CDE00_0; mr. 31,3; beq 2f; lwz 9,0x0(31); li 30,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; mr 28,3; b 1f; 0:; addi 30,30,1; 1:; cmpw 30,28; bge 2f; lwz 9,0x0(31); mr 4,30; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x0(3); cmpw 0,29; bne 0b; lwz 9,0x0(31); li 27,1; lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; mtspr 8,0; blrl; stw 3,0x0(26); stw 30,0x0(25); 2:; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800CDE00_0();
extern "C" void f_800CDE00() {}
