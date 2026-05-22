// 0x8037F158 __CARDTxHandler (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 27,3,0; lis 3,-32688; addi 0,3,-24000; mulli 4,27,272; addi 3,27,0; add 29,0,4; bl _s8037F158_0; cntlzw 0,3; addi 3,27,0; rlwinm 31,0,27,5,31; bl _s8037F158_1; lwz 0,0xc8(29); cmplwi 0,0; mr 28,0; beq 3f; li 30,0; cmpwi 31,0; stw 30,0xc8(29); bne 0f; mr 3,27; bl _s8037F158_2; cmpwi 3,0; beq 0f; li 30,1; 0:; cmpwi 30,0; beq 1f; li 4,0; b 2f; 1:; li 4,-3; 2:; addi 12,28,0; mtspr 8,12; addi 3,27,0; blrl; 3:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037F158_0();
extern "C" void _s8037F158_1();
extern "C" void _s8037F158_2();
extern "C" void f_8037F158() {}
