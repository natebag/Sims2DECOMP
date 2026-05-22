// 0x802998FC AptDisplayListState::remove(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 5,0; addi 6,1,8; addi 7,1,12; bl _s802998FC_0; lwz 3,0xc(1); bl _s802998FC_1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802998FC_0();
extern "C" void _s802998FC_1();
extern "C" void f_802998FC() {}
