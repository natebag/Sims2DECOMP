// 0x802C8E18 EHashTable::Find(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); rlwinm 4,4,2,0,29; lwzx 3,4,9; cmpwi 3,0; beq 1f; 0:; lwz 0,0xc(3); cmpw 0,5; beqlr; lwz 3,0x8(3); cmpwi 3,0; bne 0b; 1:; li 3,0"
extern "C" int f_802C8E18() {}
