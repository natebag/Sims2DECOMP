// 0x8039EE00 void (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 31,3; mr 29,6; cmpw 31,30; beq 1f; 0:; lwz 0,0x0(29); mr 3,31; addi 5,1,8; stw 0,0x8(1); lwz 4,0x0(31); addi 31,31,4; bl _s8039EE00_0; cmpw 31,30; bne 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8039EE00_0();
extern "C" void f_8039EE00() {}
