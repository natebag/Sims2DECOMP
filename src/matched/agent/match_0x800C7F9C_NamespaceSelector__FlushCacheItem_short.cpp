// 0x800C7F9C NamespaceSelector::FlushCacheItem(short, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); lwz 9,0x4(5); li 10,0; lwz 0,0x0(9); b 2f; 0:; lhz 0,0x8(9); addi 11,9,8; cmpw 0,4; bne 1f; stw 10,0x8(11); lwz 9,0x8(1); sth 10,0x8(9); b 4f; 1:; stw 9,0x18(1); lwz 0,0x0(9); stw 9,0x10(1); 2:; stw 0,0x8(1); lwz 0,0x4(5); li 11,1; lwz 9,0x8(1); stw 0,0x10(1); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 0b; 4:; addi 1,1,32"
extern "C" void f_800C7F9C() {}
