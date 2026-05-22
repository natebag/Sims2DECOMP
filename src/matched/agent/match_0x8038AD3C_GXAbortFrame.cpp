// 0x8038AD3C GXAbortFrame (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); lwz 3,-17720(13); lbz 0,0x5aa(3); cmplwi 0,0; beq 4f; bl _s8038AD3C_0; cmplwi 3,0; beq 4f; lwz 3,-21988(13); addi 6,3,78; lhz 4,0x4e(3); addi 5,3,80; 0:; mr 0,4; lhz 4,0x0(6); lhz 3,0x0(5); cmplw 4,0; bne 0b; rlwinm 0,4,16,0,15; or 27,0,3; 1:; bl _s8038AD3C_1; li 0,0; addi 31,4,0; addi 30,3,0; xoris 28,0,32768; li 29,8; 2:; bl _s8038AD3C_2; subfc 4,31,4; subfe 0,30,3; xoris 3,0,32768; subfc 0,4,29; subfe 3,3,28; subfe 3,28,28; neg. 3,3; beq 2b; lwz 3,-21988(13); addi 6,3,78; lhz 4,0x4e(3); addi 5,3,80; 3:; mr 0,4; lhz 4,0x0(6); lhz 3,0x0(5); cmplw 4,0; bne 3b; rlwinm 0,4,16,0,15; or 0,0,3; cmplw 0,27; mr 27,0; bne 1b; 4:; lis 3,-13312; li 0,1; addi 27,3,12288; stwu 0,0x18(27); bl _s8038AD3C_3; li 0,0; addi 31,4,0; addi 30,3,0; xoris 28,0,32768; li 29,50; 5:; bl _s8038AD3C_4; subfc 4,31,4; subfe 0,30,3; xoris 3,0,32768; subfc 0,4,29; subfe 3,3,28; subfe 3,28,28; neg. 3,3; beq 5b; li 30,0; stw 30,0x0(27); bl _s8038AD3C_5; addi 28,4,0; addi 29,3,0; xoris 31,30,32768; li 30,5; 6:; bl _s8038AD3C_6; subfc 4,28,4; subfe 0,29,3; xoris 3,0,32768; subfc 0,4,30; subfe 3,3,31; subfe 3,31,31; neg. 3,3; beq 6b; bl _s8038AD3C_7; cmplwi 3,0; beq 8f; bl _s8038AD3C_8; bl _s8038AD3C_9; lwz 3,-17720(13); li 0,0; stw 0,0x5ac(3); lwz 0,0x5ac(3); cmplwi 0,0; beq 7f; bl _s8038AD3C_10; 7:; li 0,0; lis 3,-13311; stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); stw 0,-32768(3); bl _s8038AD3C_11; 8:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8038AD3C_0();
extern "C" void _s8038AD3C_1();
extern "C" void _s8038AD3C_2();
extern "C" void _s8038AD3C_3();
extern "C" void _s8038AD3C_4();
extern "C" void _s8038AD3C_5();
extern "C" void _s8038AD3C_6();
extern "C" void _s8038AD3C_7();
extern "C" void _s8038AD3C_8();
extern "C" void _s8038AD3C_9();
extern "C" void _s8038AD3C_10();
extern "C" void _s8038AD3C_11();
extern "C" void f_8038AD3C() {}
