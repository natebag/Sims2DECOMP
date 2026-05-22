// 0x802847E4 AptCharacterAnimation::GetIDFromImportFile(int) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; rlwinm 4,4,4,0,27; lwz 9,0x24(28); li 29,0; add 9,4,9; lwz 11,0xc(9); lwz 31,0x10(11); lwz 0,0x30(31); cmpw 29,0; bge 2f; mr 27,4; li 30,0; 0:; lwz 9,0x24(28); lwz 11,0x34(31); add 9,27,9; lwz 3,0x4(9); lwzx 4,30,11; bl _s802847E4_0; cmpwi 3,0; bne 1f; lwz 9,0x34(31); add 9,30,9; lwz 3,0x4(9); b 3f; 1:; lwz 0,0x30(31); addi 29,29,1; addi 30,30,8; cmpw 29,0; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802847E4_0();
extern "C" void f_802847E4() {}
