// 0x800948D4 PreGameState::InsertPlayer2Roommate(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; li 30,0; addi 29,9,24012; lwz 0,0x448(29); cmpwi 0,0; beq 1f; lis 9,-32697; addi 9,9,23428; addi 31,9,260; mr 3,31; bl _s800948D4_0; cmpwi 3,0; bne 0f; lwz 11,-21476(13); li 4,2; li 30,1; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,0; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-21476(13); lwz 4,0x0(3); lwz 9,0x0(11); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x158(9); lwz 0,0x15c(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s800948D4_1; lwz 11,-21476(13); li 4,19; lha 5,0x4(3); lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 0,0x44c(29); 1:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800948D4_0();
extern "C" void _s800948D4_1();
extern "C" void f_800948D4() {}
