// 0x8037F284 __CARDEnableInterrupt (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 5,4; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; li 4,0; stw 30,0x18(1); addi 30,3,0; bl _s8037F284_0; cmpwi 3,0; bne 0f; li 3,-3; b 4f; 0:; cmpwi 31,0; beq 1f; lis 0,-32511; b 2f; 1:; lis 0,-32512; 2:; stw 0,0x10(1); addi 3,30,0; addi 4,1,16; li 5,2; li 6,1; li 7,0; bl _s8037F284_1; cntlzw 0,3; addi 3,30,0; rlwinm 31,0,27,5,31; bl _s8037F284_2; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,30,0; or 31,31,0; bl _s8037F284_3; cntlzw 0,3; rlwinm 0,0,27,5,31; or. 31,31,0; beq 3f; li 3,-3; b 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037F284_0();
extern "C" void _s8037F284_1();
extern "C" void _s8037F284_2();
extern "C" void _s8037F284_3();
extern "C" void f_8037F284() {}
