// 0x8038AA5C GXResetWriteGatherPipe (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); 0:; bl _s8038AA5C_0; rlwinm. 0,3,0,31,31; bne 0b; lis 3,3073; addi 3,3,-32768; bl _s8038AA5C_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038AA5C_0();
extern "C" void _s8038AA5C_1();
extern "C" void f_8038AA5C() {}
