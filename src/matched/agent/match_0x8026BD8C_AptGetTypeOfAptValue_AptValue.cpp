// 0x8026BD8C AptGetTypeOfAptValue(AptValue (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 5,0x0(3); lis 4,-32704; addi 4,4,3724; addi 3,13,-23032; rlwinm 5,5,0,25,31; crxor 6,6,6; bl _s8026BD8C_0; addi 3,13,-23032; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026BD8C_0();
extern "C" void f_8026BD8C() {}
