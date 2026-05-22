// 0x803C6E10 void (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,4; mr 31,3; mr 28,6; cmpw 31,29; beq 1f; addi 30,1,8; 0:; lwz 0,0x0(31); mr 3,31; lwz 11,0x4(31); mr 4,30; lwz 9,0x8(31); mr 5,28; stw 0,0x8(1); addi 31,31,12; stw 11,0x4(30); stw 9,0x8(30); bl _s803C6E10_0; cmpw 31,29; bne 0b; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s803C6E10_0();
extern "C" void f_803C6E10() {}
