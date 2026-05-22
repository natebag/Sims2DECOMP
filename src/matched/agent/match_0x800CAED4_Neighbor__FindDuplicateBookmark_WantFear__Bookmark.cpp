// 0x800CAED4 Neighbor::FindDuplicateBookmark(WantFear::Bookmark (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 29,4; li 31,0; li 30,0; 0:; lwz 9,0x194(28); li 11,1; add 3,30,9; lwz 0,0x4(3); cmpwi 0,0; bne 1f; li 11,0; 1:; cmpwi 11,0; beq 2f; mr 4,29; bl _s800CAED4_0; cmpwi 3,0; beq 2f; mr 3,31; b 3f; 2:; addi 31,31,1; addi 30,30,12; cmplwi 31,19; ble 0b; li 3,-1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CAED4_0();
extern "C" void f_800CAED4() {}
