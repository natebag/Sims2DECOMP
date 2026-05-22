// 0x80181F18 UIUserDrawCBTable::AddRecord(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x8(3); lwz 9,0x4(10); stw 9,0x8(3); cmpwi 9,0; beq 0f; li 0,0; stw 0,0x0(9); 0:; stw 4,0x8(10); stw 5,0xc(10); stw 6,0x10(10); lwz 0,0x0(3); cmpwi 0,0; bne 1f; stw 10,0x0(3); stw 0,0x0(10); stw 10,0x4(3); stw 0,0x4(10); blr; 1:; lwz 9,0x4(3); li 11,0; stw 10,0x4(9); lwz 0,0x4(3); stw 0,0x0(10); stw 10,0x4(3); stw 11,0x4(10)"
extern "C" void f_80181F18() {}
