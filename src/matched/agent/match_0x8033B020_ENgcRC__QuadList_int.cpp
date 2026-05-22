// 0x8033B020 ENgcRC::QuadList(int, (740 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 16,0x20(1); stw 0,0x64(1); stw 12,0x1c(1); mr 31,3; mr 17,5; mr 26,6; mr 23,7; mr 25,8; mr 18,9; mr. 30,4; beq 13f; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lwz 9,0x0(31); lis 3,-32691; addi 3,3,21688; mr 4,30; lwz 0,0x54(9); add 0,0,30; stw 0,0x54(9); li 10,0; li 9,0; stw 18,0x8(1); bl _s8033B020_0; b 13f; 0:; cmpwi 26,0; rlwinm 29,30,4,0,27; li 22,0; mfcr 28; cmpwi 2,18,0; beq 1f; mr 22,29; bne cr2,1f; rlwinm 22,30,3,0,28; 1:; li 21,0; cmpwi 4,25,0; beq cr4,2f; rlwinm 21,30,2,0,29; 2:; li 19,0; cmpwi 3,23,0; beq cr3,3f; rlwinm 19,30,2,0,29; 3:; addi 0,29,31; mr 3,31; rlwinm 4,0,0,0,26; li 5,32; add 4,4,22; li 24,0; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,21; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,19; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s8033B020_1; mr 27,3; mtcrf 128,28; add 9,27,29; addi 0,9,31; rlwinm 9,0,0,0,26; beq 4f; mr 24,9; add 9,24,22; addi 0,9,31; rlwinm 9,0,0,0,26; 4:; li 28,0; beq cr4,5f; mr 28,9; add 9,28,21; addi 0,9,31; rlwinm 9,0,0,0,26; 5:; li 20,0; beq cr3,6f; mr 20,9; 6:; mr 4,17; mr 5,29; mr 3,27; li 16,0; crxor 6,6,6; bl _s8033B020_2; li 17,0; mr 4,26; mr 5,22; mr 3,24; crxor 6,6,6; bl _s8033B020_3; mr 4,25; mr 5,21; mr 3,28; crxor 6,6,6; bl _s8033B020_4; mr 4,23; mr 5,19; mr 3,20; crxor 6,6,6; bl _s8033B020_5; mr 4,29; mr 3,27; bl _s8033B020_6; cmpwi 24,0; beq 7f; mr 4,22; mr 3,24; bl _s8033B020_7; 7:; cmpwi 20,0; beq 8f; mr 4,19; mr 3,20; bl _s8033B020_8; 8:; cmpwi 28,0; beq 9f; mr 4,21; mr 3,28; bl _s8033B020_9; 9:; bl _s8033B020_10; lwz 0,-26320(13); cmpwi 0,0; beq 10f; lwz 4,0x0(31); addi 0,1,16; lis 3,-32691; stw 0,0x8(1); addi 3,3,21688; stw 18,0xc(1); li 5,128; mr 6,30; mr 7,27; mr 8,24; mr 9,20; mr 10,28; bl _s8033B020_11; lwz 16,0x10(1); mr 17,3; 10:; lwz 9,0x70(31); li 4,2; li 5,8; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,30; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,3; stw 30,0x4(3); stb 0,0x0(3); beq cr2,11f; li 0,1; stb 0,0x1(3); b 12f; 11:; stb 18,0x1(3); 12:; stw 17,0x1c(3); stw 27,0x8(3); stw 24,0xc(3); stw 20,0x10(3); stw 28,0x14(3); stw 16,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 13:; lwz 0,0x64(1); lwz 12,0x1c(1); mtspr 8,0; lmw 16,0x20(1); mtcrf 56,12; addi 1,1,96"
extern "C" void _s8033B020_0();
extern "C" void _s8033B020_1();
extern "C" void _s8033B020_2();
extern "C" void _s8033B020_3();
extern "C" void _s8033B020_4();
extern "C" void _s8033B020_5();
extern "C" void _s8033B020_6();
extern "C" void _s8033B020_7();
extern "C" void _s8033B020_8();
extern "C" void _s8033B020_9();
extern "C" void _s8033B020_10();
extern "C" void _s8033B020_11();
extern "C" void f_8033B020() {}
