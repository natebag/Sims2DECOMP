// 0x8030F5B4 EREdithTreeSet::Read(EStream (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8030F5B4_0; cmpwi 3,0; beq 0f; li 9,0; stw 9,0x0(9); 0:; .long 0x00000001; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8030F5B4_0();
extern "C" void f_8030F5B4() {}
