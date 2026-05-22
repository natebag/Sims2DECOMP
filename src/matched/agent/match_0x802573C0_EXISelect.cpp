// 0x802573C0 EXISelect (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bl _s802573C0_0; mr 30,3; lwz 0,0xc(31); rlwinm. 0,0,0,29,29; bne 1f; cmpwi 27,2; beq 2f; cmplwi 28,0; bne 0f; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 0f; mr 3,27; bl _s802573C0_1; cmpwi 3,0; beq 1f; 0:; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 1f; lwz 0,0x18(31); cmplw 0,28; beq 2f; 1:; mr 3,30; bl _s802573C0_2; li 3,0; b 6f; 2:; lwz 0,0xc(31); ori 0,0,4; stw 0,0xc(31); mulli 0,27,20; lis 3,-13312; addi 4,3,26624; add 4,4,0; lwz 5,0x0(4); andi. 5,5,1029; li 0,1; slw 0,0,28; rlwinm 3,0,7,0,24; rlwinm 0,29,4,0,27; or 0,3,0; or 5,5,0; stw 5,0x0(4); lwz 0,0xc(31); rlwinm. 0,0,0,28,28; beq 5f; cmpwi 27,1; beq 4f; bge 5f; cmpwi 27,0; bge 3f; b 5f; 3:; lis 3,16; bl _s802573C0_3; b 5f; 4:; lis 3,2; bl _s802573C0_4; 5:; mr 3,30; bl _s802573C0_5; li 3,1; 6:; lwz 0,0x34(1); lmw 27,0x1c(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802573C0_0();
extern "C" void _s802573C0_1();
extern "C" void _s802573C0_2();
extern "C" void _s802573C0_3();
extern "C" void _s802573C0_4();
extern "C" void _s802573C0_5();
extern "C" void f_802573C0() {}
