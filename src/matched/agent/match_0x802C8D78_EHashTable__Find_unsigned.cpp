// 0x802C8D78 EHashTable::Find(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); lwz 11,0x8(3); divwu 9,4,0; mullw 9,9,0; subf 9,9,4; rlwinm 9,9,2,0,29; lwzx 3,9,11; cmpwi 3,0; beq 2f; cmpwi 7,5,0; 0:; lwz 0,0xc(3); cmpw 0,4; bne 1f; beqlr cr7; lwz 0,0x10(3); stw 0,0x0(5); blr; 1:; lwz 3,0x8(3); cmpwi 3,0; bne 0b; 2:; li 3,0"
extern "C" void f_802C8D78() {}
