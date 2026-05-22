// 0x802CAA40 EMat4::LookAt(EVec3 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 30,3; addi 29,1,8; bl _s802CAA40_0; mr 4,30; mr 3,29; bl _s802CAA40_1; mr 4,29; mr 3,30; bl _s802CAA40_2; mr 3,30; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s802CAA40_0();
extern "C" void _s802CAA40_1();
extern "C" void _s802CAA40_2();
extern "C" void f_802CAA40() {}
