// 0x802CCA7C ENodeList::Search(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); b 1f; 0:; lwz 0,0x0(3); cmpw 0,4; beqlr; lwz 3,0x8(3); 1:; li 0,1; cmpwi 3,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; li 3,0"
extern "C" int f_802CCA7C() {}
