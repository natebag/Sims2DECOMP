// 0x803AF7F0 TreeTableEntry::GetAdByID(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,-23892(13); cmpwi 11,0; bne 0f; addi 9,13,-23900; li 0,1; sth 11,0x6(9); stw 0,-23892(13); sth 11,0x0(9); sth 11,0x2(9); sth 11,0x4(9); 0:; li 10,0; lwz 11,0x4(3); b 2f; 1:; rlwinm 0,10,3,0,28; add 3,11,0; lha 9,0x6(3); cmpw 9,4; beqlr; addi 10,10,1; 2:; cmpwi 11,0; li 0,0; beq 3f; lwz 0,-4(11); 3:; cmpw 10,0; blt 1b; addi 3,13,-23900"
extern "C" void f_803AF7F0() {}
