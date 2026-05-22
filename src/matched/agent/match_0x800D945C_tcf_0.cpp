// 0x800D945C __tcf_0 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,13,-24280; li 4,2; bl _s800D945C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800D945C_0();
extern "C" void f_800D945C() {}
