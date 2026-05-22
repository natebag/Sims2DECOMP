// 0x802CFE38 __tcf_0 (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32694; li 4,2; addi 3,3,-10584; bl _s802CFE38_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CFE38_0();
extern "C" void f_802CFE38() {}
