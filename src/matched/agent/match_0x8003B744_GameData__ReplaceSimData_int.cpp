// 0x8003B744 GameData::ReplaceSimData(int, (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,5; mr 29,6; mr 31,7; mr. 4,4; bge 2f; lis 3,-32707; addi 3,3,7660; bl _s8003B744_0; cmpwi 3,0; bne 0f; lis 9,-32697; lwz 4,0x6214(9); cmpwi 4,0; bne 1f; li 4,1; b 1f; 0:; lis 9,-32697; lwz 4,0x6218(9); 1:; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,31; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-21476(13); lwz 4,0x0(3); lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; b 3f; 2:; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; 3:; blrl; mr 31,3; mulli 0,29,392; lwz 4,0x78(30); mr 3,31; add 4,4,0; bl _s8003B744_1; cmpwi 28,0; beq 4f; li 0,1; mr 3,31; sth 0,0xa4(31); bl _s8003B744_2; lwz 9,0x78(30); lwz 11,0x0(3); lwz 4,0x650(9); lha 0,0x88(11); lwz 9,0x8c(11); add 3,3,0; mtspr 8,9; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8003B744_0();
extern "C" void _s8003B744_1();
extern "C" void _s8003B744_2();
extern "C" void f_8003B744() {}
