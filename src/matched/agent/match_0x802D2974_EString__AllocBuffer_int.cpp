// 0x802D2974 EString::AllocBuffer(int) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; bl _s802D2974_0; mr 4,30; li 5,0; bl _s802D2974_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D2974_0();
extern "C" void _s802D2974_1();
extern "C" void f_802D2974() {}
