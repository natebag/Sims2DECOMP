// 0x800B8880 GoalUnlock::GrantUnlock(IGoalUnlock::UnlockType, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr. 30,5; blt 1f; lwz 9,0x0(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; cmpw 30,3; bge 1f; mr 3,31; mr 4,29; bl _s800B8880_0; add 0,30,30; extsh 9,0; mr 0,9; cmpwi 9,0; bge 0f; addi 0,9,15; 0:; srawi 0,0,4; addi 8,31,4; add 10,3,0; mr 4,29; rlwinm 0,0,4,0,27; add 10,10,10; subf 0,0,9; lhzx 11,8,10; extsh 0,0; li 9,1; slw 9,9,0; mr 5,30; or 11,11,9; li 6,1; sthx 11,8,10; lwz 9,0x0(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B8880_0();
extern "C" void f_800B8880() {}
