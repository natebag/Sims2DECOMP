// 0x802D67F4 EVec3Decomp::ReadAllVs(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 4,2; lwz 5,0x8(30); addi 6,30,44; bl _s802D67F4_0; lwz 5,0x8(30); mr 3,30; li 4,1; addi 6,30,56; bl _s802D67F4_1; lwz 29,0x8(30); mr 3,30; li 4,0; addi 6,30,68; addi 29,29,1; mr 5,29; bl _s802D67F4_2; mr 3,30; mr 5,29; li 4,2; addi 6,3,80; bl _s802D67F4_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D67F4_0();
extern "C" void _s802D67F4_1();
extern "C" void _s802D67F4_2();
extern "C" void _s802D67F4_3();
extern "C" void f_802D67F4() {}
