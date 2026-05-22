// 0x800B8A6C GoalUnlock::IsRecentlyUnlocked(IGoalUnlock::UnlockType, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr. 31,5; blt 1f; lwz 9,0x0(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; cmpw 31,3; bge 1f; mr 4,29; mr 3,30; bl _s800B8A6C_0; add 9,31,31; addi 9,9,1; extsh 5,9; mr 0,5; cmpwi 5,0; bge 0f; addi 0,5,15; 0:; srawi 0,0,4; addi 8,30,4; rlwinm 11,0,4,0,27; li 9,1; add 0,3,0; subf 11,11,5; add 0,0,0; extsh 11,11; slw 9,9,11; lhax 10,8,0; rlwinm 9,9,0,16,31; li 3,1; and. 0,10,9; bne 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B8A6C_0();
extern "C" void f_800B8A6C() {}
