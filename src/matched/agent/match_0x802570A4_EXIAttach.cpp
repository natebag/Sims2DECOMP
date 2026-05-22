// 0x802570A4 EXIAttach (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 27,0x2c(1); addi 27,3,0; addi 28,4,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 30,0,4; addi 3,27,0; bl _s802570A4_0; cmpwi 3,0; beq 0f; lwz 0,0x20(30); cmpwi 0,0; bne 0f; addi 3,27,0; li 4,0; addi 5,1,28; bl _s802570A4_1; 0:; bl _s802570A4_2; mr 29,3; lwz 0,0x20(30); cmpwi 0,0; bne 1f; mr 3,29; bl _s802570A4_3; li 3,0; b 5f; 1:; bl _s802570A4_4; mr 31,3; lwz 0,0xc(30); rlwinm. 0,0,0,28,28; bne 2f; mr 3,27; bl _s802570A4_5; cmpwi 3,0; bne 3f; 2:; mr 3,31; bl _s802570A4_6; li 31,0; b 4f; 3:; addi 3,27,0; li 4,1; li 5,0; li 6,0; bl _s802570A4_7; stw 28,0x8(30); lis 3,16; mulli 0,27,3; srw 3,3,0; bl _s802570A4_8; lwz 0,0xc(30); ori 0,0,8; stw 0,0xc(30); mr 3,31; bl _s802570A4_9; li 31,1; 4:; mr 3,29; bl _s802570A4_10; mr 3,31; 5:; lwz 0,0x44(1); lmw 27,0x2c(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s802570A4_0();
extern "C" void _s802570A4_1();
extern "C" void _s802570A4_2();
extern "C" void _s802570A4_3();
extern "C" void _s802570A4_4();
extern "C" void _s802570A4_5();
extern "C" void _s802570A4_6();
extern "C" void _s802570A4_7();
extern "C" void _s802570A4_8();
extern "C" void _s802570A4_9();
extern "C" void _s802570A4_10();
extern "C" void f_802570A4() {}
