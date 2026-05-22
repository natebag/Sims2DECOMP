// 0x800B8B24 GoalUnlock::SetRecentlyUnlocked(IGoalUnlock::UnlockType, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,6; mr. 31,5; blt 3f; lwz 9,0x0(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; cmpw 31,3; bge 3f; mr 4,29; mr 3,30; bl _s800B8B24_0; add 9,31,31; addi 9,9,1; extsh 5,9; mr 0,5; cmpwi 5,0; bge 0f; addi 0,5,15; 0:; srawi 0,0,4; li 9,1; add 3,3,0; cmpwi 28,0; rlwinm 0,0,4,0,27; subf 0,0,5; extsh 0,0; slw 9,9,0; rlwinm 5,9,0,16,31; beq 1f; add 11,3,3; addi 9,30,4; lhzx 0,9,11; or 0,5,0; b 2f; 1:; add 11,3,3; addi 9,30,4; lhzx 0,9,11; andc 0,0,5; 2:; sthx 0,9,11; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B8B24_0();
extern "C" void f_800B8B24() {}
