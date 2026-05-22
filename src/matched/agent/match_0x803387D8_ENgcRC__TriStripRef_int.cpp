// 0x803387D8 ENgcRC::TriStripRef(int, (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stmw 17,0x1c(1); stw 0,0x5c(1); stw 12,0x18(1); mr 30,3; mr 21,5; mr 25,6; mr 24,7; mr 23,8; mr 27,9; mr 22,10; mr. 31,4; beq 11f; cmpwi 22,0; rlwinm 4,31,4,0,27; li 29,0; cmpwi 2,25,0; mfcr 18; beq cr2,0f; mr 29,4; bne 0f; rlwinm 29,31,3,0,28; 0:; cmpwi 7,23,0; li 20,0; mfcr 28; rlwinm 28,28,28,0,3; mcrf cr0,cr7; beq 1f; rlwinm 20,31,2,0,29; 1:; li 19,0; cmpwi 3,27,0; beq cr3,2f; rlwinm 19,31,2,0,29; 2:; li 26,0; cmpwi 4,24,0; beq cr4,3f; rlwinm 26,31,2,0,29; 3:; li 17,0; mr 3,21; bl _s803387D8_0; beq cr2,4f; mr 4,29; mr 3,25; bl _s803387D8_1; 4:; beq cr4,5f; mr 4,26; mr 3,24; bl _s803387D8_2; 5:; mtcrf 128,28; beq 6f; mr 4,20; mr 3,23; bl _s803387D8_3; 6:; beq cr3,7f; mr 4,19; mr 3,27; bl _s803387D8_4; 7:; bl _s803387D8_5; lwz 0,-26320(13); cmpwi 0,0; beq 8f; bne cr3,8f; lwz 4,0x0(30); addi 0,1,16; lis 3,-32691; stw 0,0x8(1); addi 3,3,21688; stw 22,0xc(1); li 5,152; mr 6,31; mr 7,21; mr 8,25; mr 9,24; mr 10,23; bl _s803387D8_6; lwz 27,0x10(1); mr 17,3; 8:; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,31; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,42; stw 31,0x4(3); stb 0,0x0(3); mtcrf 128,18; beq 9f; li 0,1; stb 0,0x1(3); b 10f; 9:; stb 22,0x1(3); 10:; stw 17,0x1c(3); stw 21,0x8(3); stw 25,0xc(3); stw 24,0x10(3); stw 23,0x14(3); stw 27,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 11:; lwz 0,0x5c(1); lwz 12,0x18(1); mtspr 8,0; lmw 17,0x1c(1); mtcrf 56,12; addi 1,1,88"
extern "C" void _s803387D8_0();
extern "C" void _s803387D8_1();
extern "C" void _s803387D8_2();
extern "C" void _s803387D8_3();
extern "C" void _s803387D8_4();
extern "C" void _s803387D8_5();
extern "C" void _s803387D8_6();
extern "C" void f_803387D8() {}
