// 0x8017FAE4 UIScreenManager::UnloadUIScreen(UIScreenID) (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; stmw 22,0x88(1); stw 0,0xb4(1); mr 29,3; mr 26,4; bl _s8017FAE4_0; li 22,1; cmpwi 3,0; beq 4f; mr 3,29; mr 4,26; bl _s8017FAE4_1; rlwinm 3,3,4,0,27; addi 3,3,132; add. 30,29,3; beq 4f; lwz 0,0x4(30); cmpwi 0,3; beq 4f; lwz 0,0xc(30); li 22,0; lis 25,-32706; cmpwi 0,0; beq 3f; li 27,0; lis 23,-32706; li 24,1; addi 31,29,132; li 28,24; 0:; lwz 9,0x8(31); lwz 0,0xc(30); cmpw 9,0; bne 2f; lwz 0,0x4(31); cmpwi 0,3; bne 1f; stw 27,0x8(31); b 2f; 1:; lwz 5,0x0(31); addi 4,1,8; mr 3,29; bl _s8017FAE4_2; lwz 3,-25136(13); addi 4,25,15128; li 5,0; li 6,0; li 7,2; addi 8,23,15156; addi 9,1,8; crxor 6,6,6; bl _s8017FAE4_3; stw 27,0x8(31); stw 24,0x4(31); 2:; addi 31,31,16; addic. 28,28,-1; bne 0b; li 0,0; stw 0,0xc(30); 3:; lwz 5,0x0(30); addi 4,1,8; mr 3,29; bl _s8017FAE4_4; lwz 3,-25136(13); lis 4,-32706; lis 8,-32706; addi 4,4,15128; addi 8,8,15172; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017FAE4_5; li 0,3; stw 0,0x4(30); 4:; cmpwi 22,0; beq 7f; li 28,0; li 30,0; addi 31,29,516; 5:; lwz 0,0x0(31); addi 31,31,4; cmpw 0,26; bne 6f; li 28,1; mr 3,29; mr 4,30; bl _s8017FAE4_6; 6:; addi 30,30,1; cmpwi 30,7; bgt 7f; cmpwi 28,0; beq 5b; 7:; li 3,0; lwz 0,0xb4(1); mtspr 8,0; lmw 22,0x88(1); addi 1,1,176"
extern "C" void _s8017FAE4_0();
extern "C" void _s8017FAE4_1();
extern "C" void _s8017FAE4_2();
extern "C" void _s8017FAE4_3();
extern "C" void _s8017FAE4_4();
extern "C" void _s8017FAE4_5();
extern "C" void _s8017FAE4_6();
extern "C" void f_8017FAE4() {}
