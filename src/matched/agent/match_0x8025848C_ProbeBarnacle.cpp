// 0x8025848C ProbeBarnacle (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; cmpwi 29,2; stw 28,0x18(1); beq 0f; cmplwi 30,0; bne 0f; addi 3,29,0; li 4,0; bl _s8025848C_0; cmpwi 3,0; bne 0f; li 3,0; b 6f; 0:; addi 3,29,0; addi 4,30,0; li 5,0; bl _s8025848C_1; cntlzw 0,3; rlwinm 0,0,27,5,31; mr. 28,0; bne 2f; addi 3,29,0; addi 4,30,0; li 5,0; bl _s8025848C_2; cntlzw 0,3; rlwinm 0,0,27,5,31; mr. 28,0; bne 1f; lis 3,8193; addi 0,3,4864; stw 0,0x14(1); addi 3,29,0; addi 4,1,20; li 5,4; li 6,1; li 7,0; bl _s8025848C_3; cntlzw 0,3; addi 3,29,0; rlwinm 28,0,27,5,31; bl _s8025848C_4; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,29,0; addi 4,31,0; or 28,28,0; li 5,4; li 6,0; li 7,0; bl _s8025848C_5; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,29,0; or 28,28,0; bl _s8025848C_6; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,29,0; or 28,28,0; bl _s8025848C_7; cntlzw 0,3; rlwinm 0,0,27,5,31; or 28,28,0; 1:; mr 3,29; bl _s8025848C_8; 2:; cmpwi 29,2; beq 3f; cmplwi 30,0; bne 3f; mr 3,29; bl _s8025848C_9; 3:; cmpwi 28,0; beq 4f; li 3,0; b 6f; 4:; lwz 3,0x0(31); addis 0,3,1; cmplwi 0,65535; beq 5f; li 3,1; b 6f; 5:; li 3,0; 6:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025848C_0();
extern "C" void _s8025848C_1();
extern "C" void _s8025848C_2();
extern "C" void _s8025848C_3();
extern "C" void _s8025848C_4();
extern "C" void _s8025848C_5();
extern "C" void _s8025848C_6();
extern "C" void _s8025848C_7();
extern "C" void _s8025848C_8();
extern "C" void _s8025848C_9();
extern "C" void f_8025848C() {}
