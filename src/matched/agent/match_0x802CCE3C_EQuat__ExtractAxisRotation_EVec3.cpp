// 0x802CCE3C EQuat::ExtractAxisRotation(EVec3 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,4; addi 5,1,24; addi 4,1,8; bl _s802CCE3C_0; mr 4,30; addi 3,1,8; bl _s802CCE3C_1; lfs f0,0x18(1); fmuls f1,f1,f0; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s802CCE3C_0();
extern "C" void _s802CCE3C_1();
extern "C" void f_802CCE3C() {}
