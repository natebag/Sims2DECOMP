// 0x802C8DD0 EHashTable::FindNext(HTIteratorPtrType (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,4; lwz 9,0xc(3); lwz 3,0x8(3); cmpwi 3,0; beq 2f; cmpwi 7,5,0; 0:; lwz 0,0xc(3); cmpw 0,9; bne 1f; beqlr cr7; lwz 0,0x10(3); stw 0,0x0(5); blr; 1:; lwz 3,0x8(3); cmpwi 3,0; bne 0b; 2:; li 3,0"
extern "C" void f_802C8DD0() {}
