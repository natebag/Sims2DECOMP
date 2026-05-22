// 0x800D13D4 NeighborhoodImpl::NotifyAllNeighbors(WantFear::Notification (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); addi 9,3,116; lwz 31,0x74(3); lwz 0,0x4(9); mr 27,4; mr 28,5; li 30,0; cmpw 31,0; beq 3f; mr 29,9; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 2f; cmpw 3,28; beq 2f; mr 4,27; li 5,1; bl _s800D13D4_0; mr 0,3; mr 3,30; cmpw 3,0; bge 1f; mr 3,0; 1:; stw 3,0x8(1); mr 30,3; 2:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 3:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800D13D4_0();
extern "C" void f_800D13D4() {}
