// 0x802D0400 __tcf_9 (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32694; li 4,2; addi 3,3,1440; bl _s802D0400_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D0400_0();
extern "C" void f_802D0400() {}
