// 0x802CE660 ERedBlackTree::operator==(ERedBlackTree (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); lwz 4,0x0(4); b 4f; 0:; li 0,1; cmpwi 4,0; bne 1f; li 0,0; 1:; cmpwi 0,0; beq 2f; lwz 9,0x18(3); lwz 0,0x18(4); cmpw 9,0; bne 2f; lwz 9,0x1c(3); lwz 0,0x1c(4); cmpw 9,0; beq 3f; 2:; li 3,0; blr; 3:; lwz 3,0x10(3); lwz 4,0x10(4); 4:; li 0,1; cmpwi 3,0; bne 5f; li 0,0; 5:; cmpwi 0,0; bne 0b; cmpwi 4,0; li 3,1; bne 6f; li 3,0; 6:; xori 3,3,1"
extern "C" int f_802CE660() {}
