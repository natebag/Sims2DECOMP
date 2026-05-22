// 0x802D11B0 __builtin_new (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802D11B0_0; mr 4,30; li 5,0; bl _s802D11B0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D11B0_0();
extern "C" void _s802D11B0_1();
extern "C" void f_802D11B0() {}
