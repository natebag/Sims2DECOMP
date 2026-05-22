// 0x80149924 TreeTable::GetIndexByTreeID(short, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 8,0; cmpwi 9,0; beq 0f; lwz 8,-4(9); 0:; li 3,0; cmpw 3,8; bge 3f; mr 10,9; 1:; mulli 9,3,36; lhax 0,10,9; add 11,10,9; cmpw 0,4; bne 2f; lha 0,0x2(11); cmpw 0,5; beqlr; 2:; addi 0,3,1; extsh 3,0; cmpw 3,8; blt 1b; 3:; li 3,-1"
extern "C" int f_80149924() {}
