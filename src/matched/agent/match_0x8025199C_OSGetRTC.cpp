// 0x8025199C __OSGetRTC (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 26,0x18(1); addi 26,3,0; li 27,0; lis 31,8192; 0:; li 3,0; li 4,1; li 5,0; bl _s8025199C_0; cmpwi 3,0; bne 1f; li 0,0; b 3f; 1:; li 3,0; li 4,1; li 5,3; bl _s8025199C_1; cmpwi 3,0; bne 2f; li 3,0; bl _s8025199C_2; li 0,0; b 3f; 2:; stw 31,0x10(1); addi 4,1,16; li 3,0; li 5,4; li 6,1; li 7,0; bl _s8025199C_3; cntlzw 0,3; rlwinm 29,0,27,5,31; li 3,0; bl _s8025199C_4; cntlzw 0,3; rlwinm 0,0,27,5,31; or 29,29,0; addi 4,1,16; li 3,0; li 5,4; li 6,0; li 7,0; bl _s8025199C_5; cntlzw 0,3; rlwinm 0,0,27,5,31; or 29,29,0; li 3,0; bl _s8025199C_6; cntlzw 0,3; rlwinm 0,0,27,5,31; or 29,29,0; li 3,0; bl _s8025199C_7; cntlzw 0,3; rlwinm 0,0,27,5,31; or 29,29,0; li 3,0; bl _s8025199C_8; cntlzw 0,29; lwz 29,0x10(1); rlwinm 0,0,27,5,31; 3:; cntlzw 0,0; rlwinm 30,0,27,5,31; li 3,0; li 4,1; li 5,0; bl _s8025199C_9; cmpwi 3,0; bne 4f; li 0,0; b 6f; 4:; li 3,0; li 4,1; li 5,3; bl _s8025199C_10; cmpwi 3,0; bne 5f; li 3,0; bl _s8025199C_11; li 0,0; b 6f; 5:; stw 31,0xc(1); addi 4,1,12; li 3,0; li 5,4; li 6,1; li 7,0; bl _s8025199C_12; cntlzw 0,3; rlwinm 28,0,27,5,31; li 3,0; bl _s8025199C_13; cntlzw 0,3; rlwinm 0,0,27,5,31; or 28,28,0; addi 4,1,12; li 3,0; li 5,4; li 6,0; li 7,0; bl _s8025199C_14; cntlzw 0,3; rlwinm 0,0,27,5,31; or 28,28,0; li 3,0; bl _s8025199C_15; cntlzw 0,3; rlwinm 0,0,27,5,31; or 28,28,0; li 3,0; bl _s8025199C_16; cntlzw 0,3; rlwinm 0,0,27,5,31; or 28,28,0; li 3,0; bl _s8025199C_17; cntlzw 0,28; lwz 28,0xc(1); rlwinm 0,0,27,5,31; 6:; cntlzw 0,0; rlwinm 0,0,27,5,31; or. 0,30,0; bne 8f; cmplw 29,28; bne 7f; stw 29,0x0(26); li 3,1; b 9f; 7:; addi 27,27,1; cmpwi 27,16; blt 0b; 8:; li 3,0; 9:; lmw 26,0x18(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8025199C_0();
extern "C" void _s8025199C_1();
extern "C" void _s8025199C_2();
extern "C" void _s8025199C_3();
extern "C" void _s8025199C_4();
extern "C" void _s8025199C_5();
extern "C" void _s8025199C_6();
extern "C" void _s8025199C_7();
extern "C" void _s8025199C_8();
extern "C" void _s8025199C_9();
extern "C" void _s8025199C_10();
extern "C" void _s8025199C_11();
extern "C" void _s8025199C_12();
extern "C" void _s8025199C_13();
extern "C" void _s8025199C_14();
extern "C" void _s8025199C_15();
extern "C" void _s8025199C_16();
extern "C" void _s8025199C_17();
extern "C" void f_8025199C() {}
