// 0x8018019C UIScreenManager::SetVariable(char (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 26,0x88(1); stw 0,0xa4(1); mr 29,3; mr 26,5; lis 3,-32706; addi 3,3,15016; bl _s8018019C_0; cmpwi 3,0; bne 4f; lis 9,-32702; li 27,0; addi 30,9,18208; li 28,0; 0:; mr 31,30; addi 30,31,24; lwz 5,-24(30); cmpwi 5,69; bne 1f; li 28,1; b 2f; 1:; addi 4,1,8; mr 3,29; bl _s8018019C_1; addi 3,1,8; mr 4,26; bl _s8018019C_2; cmpwi 3,0; bne 2f; li 27,1; 2:; cmpwi 27,0; bne 3f; cmpwi 28,0; beq 0b; b 4f; 3:; lwz 4,0x0(31); mr 3,29; bl _s8018019C_3; cmpwi 3,-1; beq 4f; rlwinm 9,3,4,0,27; li 0,0; addi 9,9,132; stwx 0,29,9; add 9,29,9; stw 0,0xc(9); stw 0,0x4(9); stw 0,0x8(9); 4:; lwz 0,0xa4(1); mtspr 8,0; lmw 26,0x88(1); addi 1,1,160"
extern "C" void _s8018019C_0();
extern "C" void _s8018019C_1();
extern "C" void _s8018019C_2();
extern "C" void _s8018019C_3();
extern "C" void f_8018019C() {}
