// 0x8017F884 UIScreenManager::LoadUIScreen(UIScreenID, (608 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-392(1); mfspr 0,8; stmw 27,0x174(1); stw 0,0x18c(1); mr 31,3; mr 30,4; mr 27,5; li 29,0; bl _s8017F884_0; li 28,0; cmpwi 3,0; bne 13f; mr 3,31; mr 4,30; bl _s8017F884_1; mr. 29,3; bne 0f; li 3,0; b 18f; 0:; lwz 0,0x4(29); cmpwi 0,1; bne 1f; mr 3,31; bl _s8017F884_2; b 9f; 1:; cmpwi 0,3; bne 3f; lis 9,-32706; addi 11,1,8; addi 9,9,15060; li 10,48; 2:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(9); mr 3,31; addi 4,1,8; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); b 8f; 3:; cmpwi 0,4; bne 10f; li 0,68; addi 4,1,80; mtspr 9,0; li 11,1; li 9,0; mr 10,4; 4:; cmplwi 11,51; bgt 5f; cmplwi 11,50; bge 7f; cmpwi 11,41; b 6f; 5:; cmpwi 11,64; 6:; beq 7f; stw 11,0x0(10); addi 9,9,1; addi 10,10,4; 7:; addi 11,11,1; bdnz 4b; rlwinm 9,9,2,0,29; li 0,69; stwx 0,4,9; mr 3,31; 8:; bl _s8017F884_3; 9:; mr 28,3; 10:; lwz 0,0x10(29); cmpwi 0,0; bne 11f; addi 0,27,48; lis 4,-32706; rlwinm 0,0,8,0,23; lis 8,-32706; sth 0,0x168(1); lwz 3,-25136(13); addi 4,4,15128; lwz 9,0x14(29); addi 8,8,15136; li 5,0; li 6,0; li 7,3; addi 10,1,360; crxor 6,6,6; bl _s8017F884_4; b 12f; 11:; addi 3,1,8; bl _s8017F884_5; lwz 4,0x10(29); addi 3,1,8; lwz 5,0xc(29); mr 6,27; bl _s8017F884_6; addi 3,1,8; li 4,2; bl _s8017F884_7; 12:; lwz 5,0x8(29); mr 4,30; mr 3,31; li 29,1; bl _s8017F884_8; mr 3,31; mr 4,30; mr 5,28; bl _s8017F884_9; b 17f; 13:; addi 3,31,516; li 10,0; mr 8,3; li 11,0; li 9,0; 14:; lwzx 0,9,8; cmpwi 0,0; bne 15f; li 10,1; stwx 30,9,3; b 16f; 15:; cmpw 0,30; bne 16f; li 10,1; 16:; addi 11,11,1; addi 9,9,4; cmpwi 11,7; bgt 17f; cmpwi 10,0; beq 14b; 17:; mr 3,29; 18:; lwz 0,0x18c(1); mtspr 8,0; lmw 27,0x174(1); addi 1,1,392"
extern "C" void _s8017F884_0();
extern "C" void _s8017F884_1();
extern "C" void _s8017F884_2();
extern "C" void _s8017F884_3();
extern "C" void _s8017F884_4();
extern "C" void _s8017F884_5();
extern "C" void _s8017F884_6();
extern "C" void _s8017F884_7();
extern "C" void _s8017F884_8();
extern "C" void _s8017F884_9();
extern "C" void f_8017F884() {}
