// 0x800758BC SimsMemCardWrap::SaveGame(int, (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 31,9,24012; mr 28,4; lwz 0,0xc8(31); mr 29,5; cmpwi 0,0; beq 0f; lis 9,-32697; addi 9,9,23428; lwz 0,0xe8(9); cmpwi 0,0; bne 0f; lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x190(9); lwz 0,0x194(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0xc8(31); lwz 4,0x54(9); bl _s800758BC_0; 0:; lwz 11,-21476(13); lwz 4,-32056(13); lwz 9,0x0(11); lwz 5,-32040(13); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; bne 1f; cmpwi 29,0; beq 2f; 1:; bl _s800758BC_1; cmpwi 3,0; li 3,0; beq 4f; 2:; lwz 3,-32056(13); rlwinm 5,30,0,24,31; lwz 4,-31932(13); bl _s800758BC_2; mr 31,3; cmpwi 31,1; bne 4f; mr 3,30; bl _s800758BC_3; mr 31,3; mr 4,30; lwz 3,-31932(13); bl _s800758BC_4; cmpwi 28,0; beq 3f; mr 3,30; bl _s800758BC_5; mr 31,3; 3:; mr 3,31; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800758BC_0();
extern "C" void _s800758BC_1();
extern "C" void _s800758BC_2();
extern "C" void _s800758BC_3();
extern "C" void _s800758BC_4();
extern "C" void _s800758BC_5();
extern "C" void f_800758BC() {}
