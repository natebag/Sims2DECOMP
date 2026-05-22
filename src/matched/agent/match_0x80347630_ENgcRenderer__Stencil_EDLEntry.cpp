// 0x80347630 ENgcRenderer::Stencil(EDLEntry (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x510(30); cmpwi 0,0; beq 0f; li 4,0; bl _s80347630_0; 0:; lbz 0,0x3(31); li 29,0; lbz 9,0x1(31); lbz 31,0x2(31); cmpwi 0,0; beq 1f; xori 0,0,1; addic 0,0,-1; subfe 0,0,0; rlwinm 29,0,0,25,25; 1:; cmpwi 9,1; beq 6f; bgt 2f; cmpwi 9,0; beq 3f; b 7f; 2:; cmpwi 9,2; beq 4f; b 7f; 3:; li 3,1; b 5f; 4:; li 3,0; 5:; bl _s80347630_1; li 3,1; bl _s80347630_2; mr 4,29; li 3,1; bl _s80347630_3; b 7f; 6:; li 3,1; bl _s80347630_4; li 3,0; bl _s80347630_5; mr 4,29; li 3,1; bl _s80347630_6; 7:; cmpwi 31,0; bne 8f; lwz 9,0x4d8(30); li 11,1; lwz 0,0x6cc(9); stw 31,0x6e4(9); oris 0,0,32768; stw 11,0x6dc(9); ori 0,0,64; stw 11,0x6d8(9); stw 0,0x6cc(9); stw 31,0x6e0(9); b 10f; 8:; cmpwi 31,2; bne 9f; lwz 11,0x4d8(30); li 8,6; li 7,7; li 10,1; lwz 9,0x6cc(11); li 0,0; stw 0,0x6e4(11); oris 9,9,32768; stw 10,0x6d8(11); ori 9,9,64; stw 8,0x6dc(11); stw 9,0x6cc(11); stw 7,0x6e0(11); b 10f; 9:; cmpwi 31,1; bne 10f; lwz 9,0x4d8(30); li 10,7; li 8,6; li 11,0; lwz 0,0x6cc(9); stw 11,0x6e4(9); oris 0,0,32768; stw 31,0x6d8(9); ori 0,0,64; stw 10,0x6dc(9); stw 0,0x6cc(9); stw 8,0x6e0(9); 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80347630_0();
extern "C" void _s80347630_1();
extern "C" void _s80347630_2();
extern "C" void _s80347630_3();
extern "C" void _s80347630_4();
extern "C" void _s80347630_5();
extern "C" void _s80347630_6();
extern "C" void f_80347630() {}
