// 0x8004516C ObjectSaveIDTable::findHRSel(short) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 10,0; li 3,0; addis 9,9,1; lwz 0,0x6004(9); addi 7,9,24580; addi 8,9,-32764; cmpw 3,0; bgelr; lha 0,0xc(8); cmpw 0,4; bne 0f; mr 3,8; blr; 0:; lwz 0,0x0(7); addi 10,10,1; cmpw 10,0; bgelr; mulli 0,10,28; add 11,0,8; lha 9,0xc(11); cmpw 9,4; bne 0b; mr 3,11"
extern "C" int f_8004516C() {}
