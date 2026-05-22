// 0x802574EC EXIDeselect (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); addi 31,3,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 30,0,4; bl _s802574EC_0; mr 28,3; lwz 0,0xc(30); rlwinm. 0,0,0,29,29; bne 0f; mr 3,28; bl _s802574EC_1; li 3,0; b 6f; 0:; lwz 0,0xc(30); rlwinm 0,0,0,30,28; stw 0,0xc(30); mulli 0,31,20; lis 3,-13312; addi 3,3,26624; add 3,3,0; lwz 29,0x0(3); andi. 0,29,1029; stw 0,0x0(3); lwz 0,0xc(30); rlwinm. 0,0,0,28,28; beq 3f; cmpwi 31,1; beq 2f; bge 3f; cmpwi 31,0; bge 1f; b 3f; 1:; lis 3,16; bl _s802574EC_2; b 3f; 2:; lis 3,2; bl _s802574EC_3; 3:; mr 3,28; bl _s802574EC_4; cmpwi 31,2; beq 5f; rlwinm. 0,29,0,24,24; beq 5f; mr 3,31; bl _s802574EC_5; cmpwi 3,0; beq 4f; li 3,1; b 6f; 4:; li 3,0; b 6f; 5:; li 3,1; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802574EC_0();
extern "C" void _s802574EC_1();
extern "C" void _s802574EC_2();
extern "C" void _s802574EC_3();
extern "C" void _s802574EC_4();
extern "C" void _s802574EC_5();
extern "C" void f_802574EC() {}
