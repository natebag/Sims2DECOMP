// 0x80338CDC ENgcRC::TriStripRef(int, (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 17,0x24(1); stw 0,0x64(1); stw 12,0x20(1); mr 30,3; mr 18,4; mr 17,6; mr 23,7; mr 27,8; mr 26,9; mr 25,10; lwz 29,0x68(1); mr. 31,5; beq 9f; rlwinm 4,31,4,0,27; li 21,0; cmpwi 2,27,0; beq cr2,0f; rlwinm 21,31,3,0,28; 0:; cmpwi 25,0; li 20,0; mfcr 28; beq 1f; rlwinm 20,31,2,0,29; 1:; li 19,0; cmpwi 4,29,0; beq cr4,2f; rlwinm 19,31,2,0,29; 2:; li 24,0; cmpwi 3,26,0; beq cr3,3f; rlwinm 24,31,2,0,29; 3:; mr 3,23; li 22,0; bl _s80338CDC_0; mr 3,17; rlwinm 4,18,1,0,30; bl _s80338CDC_1; beq cr2,4f; mr 4,21; mr 3,27; bl _s80338CDC_2; 4:; beq cr3,5f; mr 4,24; mr 3,26; bl _s80338CDC_3; 5:; mtcrf 128,28; beq 6f; mr 4,20; mr 3,25; bl _s80338CDC_4; 6:; beq cr4,7f; mr 4,19; mr 3,29; bl _s80338CDC_5; 7:; bl _s80338CDC_6; lwz 0,-26320(13); cmpwi 0,0; beq 8f; bne cr4,8f; lwz 4,0x0(30); addi 0,1,24; lis 3,-32691; stw 22,0x14(1); stw 0,0x10(1); addi 3,3,21688; mr 6,18; mr 7,17; stw 26,0x8(1); li 5,152; stw 25,0xc(1); mr 8,31; mr 9,23; mr 10,27; bl _s80338CDC_7; lwz 29,0x18(1); mr 22,3; 8:; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,31; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,42; stw 22,0x1c(3); stb 0,0x0(3); stw 31,0x4(3); stw 23,0x8(3); stw 27,0xc(3); stw 26,0x10(3); stw 25,0x14(3); stw 29,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 9:; lwz 0,0x64(1); lwz 12,0x20(1); mtspr 8,0; lmw 17,0x24(1); mtcrf 56,12; addi 1,1,96"
extern "C" void _s80338CDC_0();
extern "C" void _s80338CDC_1();
extern "C" void _s80338CDC_2();
extern "C" void _s80338CDC_3();
extern "C" void _s80338CDC_4();
extern "C" void _s80338CDC_5();
extern "C" void _s80338CDC_6();
extern "C" void _s80338CDC_7();
extern "C" void f_80338CDC() {}
