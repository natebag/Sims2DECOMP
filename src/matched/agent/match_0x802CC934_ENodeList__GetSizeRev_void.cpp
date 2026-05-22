// 0x802CC934 ENodeList::GetSizeRev(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 3,0; b 1f; 0:; lwz 9,0x4(9); addi 3,3,1; 1:; li 0,1; cmpwi 9,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b"
extern "C" int f_802CC934() {}
