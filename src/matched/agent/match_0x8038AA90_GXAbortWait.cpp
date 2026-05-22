// 0x8038AA90 __GXAbortWait (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,3; stw 29,0x14(1); stw 28,0x10(1); bl _s8038AA90_0; li 0,0; addi 28,4,0; addi 29,3,0; rlwinm 30,30,30,2,31; xoris 31,0,32768; 0:; bl _s8038AA90_1; subfc 4,28,4; subfe 0,29,3; xoris 3,0,32768; subfc 0,4,30; subfe 3,3,31; subfe 3,31,31; neg. 3,3; beq 0b; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038AA90_0();
extern "C" void _s8038AA90_1();
extern "C" void f_8038AA90() {}
