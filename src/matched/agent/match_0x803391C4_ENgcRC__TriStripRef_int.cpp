// 0x803391C4 ENgcRC::TriStripRef(int, (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 17,0x24(1); stw 0,0x64(1); stw 12,0x20(1); mr 30,3; mr 23,5; mr 26,6; mr 25,7; mr 24,8; mr 22,9; mr 19,10; mr. 31,4; beq 12f; cmpwi 19,0; rlwinm 4,31,3,0,28; li 29,0; cmpwi 2,26,0; mfcr 17; beq cr2,0f; mr 29,4; bne 0f; rlwinm 29,31,2,0,29; 0:; cmpwi 7,24,0; li 20,0; mfcr 28; rlwinm 28,28,28,0,3; mcrf cr0,cr7; beq 1f; rlwinm 20,31,2,0,29; 1:; li 18,0; cmpwi 4,22,0; beq cr4,2f; rlwinm 18,31,2,0,29; 2:; li 27,0; cmpwi 3,25,0; beq cr3,3f; rlwinm 27,31,2,0,29; 3:; li 21,0; mr 3,23; stw 21,0x18(1); bl _s803391C4_0; beq cr2,4f; mr 4,29; mr 3,26; bl _s803391C4_1; 4:; beq cr3,5f; mr 4,27; mr 3,25; bl _s803391C4_2; 5:; mtcrf 128,28; beq 6f; mr 4,20; mr 3,24; bl _s803391C4_3; 6:; beq cr4,7f; mr 4,18; mr 3,22; bl _s803391C4_4; 7:; bl _s803391C4_5; li 29,1; bne cr4,8f; li 29,0; 8:; lwz 0,-26320(13); cmpwi 0,0; beq 9f; lwz 4,0x0(30); addi 0,1,24; lis 3,-32691; stw 0,0x8(1); stw 19,0xc(1); addi 3,3,21688; stw 29,0x10(1); li 5,152; mr 6,31; mr 7,23; mr 8,26; mr 9,25; mr 10,24; bl _s803391C4_6; mr 21,3; 9:; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,31; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,56; sth 31,0x2(3); stb 0,0x0(3); li 9,0; mtcrf 128,17; lwz 0,0x18(1); stw 0,0x4(3); beq 10f; li 9,1; 10:; mr 0,9; cmpwi 29,0; beq 11f; ori 0,0,2; 11:; stw 21,0x1c(3); stb 0,0x1(3); stw 23,0x8(3); stw 26,0xc(3); stw 25,0x10(3); stw 24,0x14(3); stw 22,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 12:; lwz 0,0x64(1); lwz 12,0x20(1); mtspr 8,0; lmw 17,0x24(1); mtcrf 56,12; addi 1,1,96"
extern "C" void _s803391C4_0();
extern "C" void _s803391C4_1();
extern "C" void _s803391C4_2();
extern "C" void _s803391C4_3();
extern "C" void _s803391C4_4();
extern "C" void _s803391C4_5();
extern "C" void _s803391C4_6();
extern "C" void f_803391C4() {}
