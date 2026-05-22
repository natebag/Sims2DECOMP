// 0x8025726C EXISelectSD (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bl _s8025726C_0; mr 30,3; lwz 0,0xc(31); rlwinm. 0,0,0,29,29; bne 3f; cmpwi 27,2; beq 4f; cmplwi 28,0; bne 2f; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 2f; mr 3,27; bl _s8025726C_1; cmpwi 3,0; beq 1f; lwz 0,0x20(31); cmpwi 0,0; bne 1f; addi 3,27,0; li 4,0; addi 5,1,24; bl _s8025726C_2; cmpwi 3,0; beq 0f; li 3,1; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 3f; 2:; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 3f; lwz 0,0x18(31); cmplw 0,28; beq 4f; 3:; mr 3,30; bl _s8025726C_3; li 3,0; b 8f; 4:; lwz 0,0xc(31); ori 0,0,4; stw 0,0xc(31); mulli 0,27,20; lis 3,-13312; addi 3,3,26624; add 3,3,0; lwz 4,0x0(3); andi. 4,4,1029; rlwinm 0,29,4,0,27; or 4,4,0; stw 4,0x0(3); lwz 0,0xc(31); rlwinm. 0,0,0,28,28; beq 7f; cmpwi 27,1; beq 6f; bge 7f; cmpwi 27,0; bge 5f; b 7f; 5:; lis 3,16; bl _s8025726C_4; b 7f; 6:; lis 3,2; bl _s8025726C_5; 7:; mr 3,30; bl _s8025726C_6; li 3,1; 8:; lwz 0,0x3c(1); lmw 27,0x24(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025726C_0();
extern "C" void _s8025726C_1();
extern "C" void _s8025726C_2();
extern "C" void _s8025726C_3();
extern "C" void _s8025726C_4();
extern "C" void _s8025726C_5();
extern "C" void _s8025726C_6();
extern "C" void f_8025726C() {}
