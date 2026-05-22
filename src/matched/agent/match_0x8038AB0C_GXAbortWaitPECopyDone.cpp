// 0x8038AB0C __GXAbortWaitPECopyDone (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); lwz 3,-21988(13); lhz 4,0x4e(3); addi 6,3,78; addi 5,3,80; 0:; mr 0,4; lhz 4,0x0(6); lhz 3,0x0(5); cmplw 4,0; bne 0b; rlwinm 0,4,16,0,15; or 0,0,3; 1:; mr 27,0; bl _s8038AB0C_0; li 0,0; addi 28,4,0; addi 29,3,0; xoris 31,0,32768; li 30,8; 2:; bl _s8038AB0C_1; subfc 4,28,4; subfe 0,29,3; xoris 3,0,32768; subfc 0,4,30; subfe 3,3,31; subfe 3,31,31; neg. 3,3; beq 2b; lwz 3,-21988(13); addi 6,3,78; lhz 4,0x4e(3); addi 5,3,80; 3:; mr 0,4; lhz 4,0x0(6); lhz 3,0x0(5); cmplw 4,0; bne 3b; rlwinm 0,4,16,0,15; or 0,0,3; cmplw 0,27; bne 1b; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8038AB0C_0();
extern "C" void _s8038AB0C_1();
extern "C" void f_8038AB0C() {}
