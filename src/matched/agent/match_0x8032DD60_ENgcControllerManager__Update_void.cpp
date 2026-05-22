// 0x8032DD60 ENgcControllerManager::Update(void) (564 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 29,3; addi 30,29,36; mr 3,30; bl _s8032DD60_0; mr 3,30; bl _s8032DD60_1; lbz 0,0x2e(29); lbz 9,0x3a(29); extsb 0,0; subfic 0,0,-1; addic 0,0,-1; subfe 0,0,0; extsb 9,9; cmpwi 9,-1; rlwinm 3,0,0,0,0; bne 0f; oris 3,3,16384; 0:; lbz 0,0x46(29); extsb 0,0; cmpwi 0,-1; bne 1f; oris 3,3,8192; 1:; lbz 0,0x52(29); extsb 0,0; cmpwi 0,-1; bne 2f; oris 3,3,4096; 2:; cmpwi 3,0; beq 3f; bl _s8032DD60_2; 3:; addi 28,1,8; li 26,0; mr 25,28; li 27,4; 4:; lwz 0,0x0(30); lwz 9,0x4(30); lwz 11,0x8(30); stw 0,0x8(1); stw 9,0x4(25); stw 11,0x8(25); lwz 9,-26528(13); lwzx 31,26,9; lwz 11,0x208(31); lha 3,0x80(11); lwz 0,0x84(11); add 3,31,3; mtspr 8,0; blrl; lbz 9,0x12(1); extsb 11,9; cmpwi 11,0; bne 7f; lwz 0,0x4(31); mr 3,31; li 4,1; ori 0,0,7; stw 0,0x4(31); bl _s8032DD60_3; lwz 0,0x1ac(31); cmpwi 0,0; beq 5f; lwz 3,0x1b0(31); b 6f; 5:; mr 3,31; mr 4,28; bl _s8032DD60_4; 6:; mr 4,3; mr 3,31; bl _s8032DD60_5; addi 4,1,8; li 6,0; mr 3,31; li 5,0; bl _s8032DD60_6; mr 3,31; li 4,0; li 5,0; bl _s8032DD60_7; addi 4,1,8; li 6,1; mr 3,31; li 5,0; bl _s8032DD60_8; mr 3,31; li 4,0; li 5,1; bl _s8032DD60_9; addi 4,1,8; li 6,0; mr 3,31; li 5,1; bl _s8032DD60_10; mr 3,31; li 4,1; li 5,0; bl _s8032DD60_11; mr 3,31; addi 4,1,8; li 5,1; li 6,1; bl _s8032DD60_12; mr 3,31; li 4,1; li 5,1; bl _s8032DD60_13; b 10f; 7:; addi 0,9,3; rlwinm 0,0,0,24,31; cmplwi 0,1; bgt 8f; lwz 0,0x4(31); rlwinm 0,0,0,31,29; stw 0,0x4(31); b 10f; 8:; cmpwi 11,-1; bne 9f; lwz 0,0x4(31); mr 3,31; rlwinm 0,0,0,0,28; stw 0,0x4(31); bl _s8032DD60_14; b 10f; 9:; li 0,-8; mr 3,31; stw 0,0x4(31); bl _s8032DD60_15; 10:; addi 30,30,12; addi 26,26,4; addic. 27,27,-1; bne 4b; mr 3,29; bl _s8032DD60_16; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s8032DD60_0();
extern "C" void _s8032DD60_1();
extern "C" void _s8032DD60_2();
extern "C" void _s8032DD60_3();
extern "C" void _s8032DD60_4();
extern "C" void _s8032DD60_5();
extern "C" void _s8032DD60_6();
extern "C" void _s8032DD60_7();
extern "C" void _s8032DD60_8();
extern "C" void _s8032DD60_9();
extern "C" void _s8032DD60_10();
extern "C" void _s8032DD60_11();
extern "C" void _s8032DD60_12();
extern "C" void _s8032DD60_13();
extern "C" void _s8032DD60_14();
extern "C" void _s8032DD60_15();
extern "C" void _s8032DD60_16();
extern "C" void f_8032DD60() {}
