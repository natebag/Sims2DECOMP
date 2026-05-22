// 0x8037F524 __CARDClearStatus (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,0; stw 0,0x4(1); li 5,4; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; bl _s8037F524_0; cmpwi 3,0; bne 0f; li 3,-3; b 2f; 0:; lis 0,-30464; stw 0,0xc(1); addi 3,30,0; addi 4,1,12; li 5,1; li 6,1; li 7,0; bl _s8037F524_1; cntlzw 0,3; addi 3,30,0; rlwinm 31,0,27,5,31; bl _s8037F524_2; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,30,0; or 31,31,0; bl _s8037F524_3; cntlzw 0,3; rlwinm 0,0,27,5,31; or. 31,31,0; beq 1f; li 3,-3; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037F524_0();
extern "C" void _s8037F524_1();
extern "C" void _s8037F524_2();
extern "C" void _s8037F524_3();
extern "C" void f_8037F524() {}
