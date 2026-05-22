// 0x802CC964 ENodeList::IsValidList(void) (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 30,0; lwz 9,0x0(29); b 1f; 0:; mr 30,9; lwz 9,0x8(30); 1:; li 31,1; cmpwi 9,0; bne 2f; li 31,0; 2:; cmpwi 31,0; bne 0b; lwz 0,0x4(29); cmpw 30,0; beq 9f; bl _s802CC964_0; cmpwi 3,0; beq 3f; stw 31,0x0(31); 3:; .long 0x00000001; lwz 9,0x4(29); b 5f; 4:; lwz 9,0x4(9); 5:; cmpw 9,30; beq 7f; li 0,1; cmpwi 9,0; bne 6f; li 0,0; 6:; cmpwi 0,0; bne 4b; b 14f; 7:; bl _s802CC964_1; cmpwi 3,0; beq 8f; li 9,0; stw 9,0x0(9); 8:; .long 0x00000001; b 14f; 9:; mr 9,30; li 30,0; lwz 3,0x0(29); b 11f; 10:; mr 30,9; lwz 9,0x4(30); 11:; li 31,1; cmpwi 9,0; bne 12f; li 31,0; 12:; cmpwi 31,0; bne 10b; cmpw 30,3; beq 15f; bl _s802CC964_2; cmpwi 3,0; beq 13f; stw 31,0x0(31); 13:; .long 0x00000001; 14:; li 3,0; b 16f; 15:; li 3,1; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CC964_0();
extern "C" void _s802CC964_1();
extern "C" void _s802CC964_2();
extern "C" void f_802CC964() {}
