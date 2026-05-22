// 0x803B0288 void (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; mr 29,6; cmpw 31,30; beq 1f; 0:; lwz 4,0x0(31); mr 3,31; mr 5,29; addi 31,31,4; bl _s803B0288_0; cmpw 31,30; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803B0288_0();
extern "C" void f_803B0288() {}
