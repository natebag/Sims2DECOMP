// 0x800751F8 SimsMemCardWrap::HasValidSavedGame(int, (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 11,-26384(13); mr 30,3; mr 31,4; mr 5,30; lwz 9,0x0(11); addi 6,1,8; lwz 4,-31932(13); lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,11,3; blrl; mr 0,3; cmpwi 0,1; bne 3f; lwz 9,0x8(1); cmpwi 9,0; beq 1f; lwz 3,-31932(13); mr 4,30; stw 0,0xc(1); addi 5,1,12; bl _s800751F8_0; mr 0,3; cmpwi 0,1; bne 3f; lwz 0,0xc(1); cmpwi 0,0; bne 0f; stw 0,0x0(31); b 2f; 0:; lwz 0,0x8(1); li 9,0; cmpwi 0,0; beq 1f; li 9,1; 1:; stw 9,0x0(31); 2:; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800751F8_0();
extern "C" void f_800751F8() {}
