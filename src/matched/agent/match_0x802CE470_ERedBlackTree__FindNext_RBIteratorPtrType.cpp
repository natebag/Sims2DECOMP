// 0x802CE470 ERedBlackTree::FindNext(RBIteratorPtrType (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(4); cmpwi 3,0; beq 0f; lwz 9,0x18(4); lwz 0,0x18(3); cmpw 0,9; bne 0f; cmpwi 5,0; beqlr; lwz 0,0x1c(3); stw 0,0x0(5); blr; 0:; li 3,0"
extern "C" void f_802CE470() {}
