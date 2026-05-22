// 0x802D5954 ETypeInfo::Insert(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26844(13); li 10,0; lwz 9,-26848(13); stw 0,0x24(3); stw 3,-26844(13); cmpwi 9,0; beq 3f; lwz 11,0x10(3); 0:; lwz 0,0x10(9); cmpw 0,11; beqlr; mr 10,9; cmplw 11,0; bge 1f; lwz 9,0x1c(10); b 2f; 1:; lwz 9,0x20(10); 2:; cmpwi 9,0; bne 0b; 3:; cmpwi 10,0; beq 5f; lwz 9,0x10(3); lwz 0,0x10(10); cmplw 9,0; bge 4f; stw 3,0x1c(10); b 6f; 4:; stw 3,0x20(10); b 6f; 5:; stw 3,-26848(13); 6:; li 0,0; stw 0,0x1c(3); stw 0,0x20(3)"
extern "C" void f_802D5954() {}
