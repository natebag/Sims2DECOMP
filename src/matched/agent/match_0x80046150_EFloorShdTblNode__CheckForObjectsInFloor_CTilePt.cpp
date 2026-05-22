// 0x80046150 EFloorShdTblNode::CheckForObjectsInFloor(CTilePt (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); addi 30,1,8; mr 4,3; mr 3,30; li 5,0; bl _s80046150_0; mr 31,30; lwz 0,0x4(30); cmpwi 0,0; beq 1f; 0:; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); li 3,1; rlwinm 0,0,0,29,30; cmpwi 0,0; bne 2f; mr 3,31; bl _s80046150_1; lwz 0,0x4(31); cmpwi 0,0; bne 0b; 1:; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80046150_0();
extern "C" void _s80046150_1();
extern "C" void f_80046150() {}
