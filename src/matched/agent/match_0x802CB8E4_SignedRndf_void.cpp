// 0x802CB8E4 SignedRndf(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802CB8E4_0; fadds f0,f1,f1; lis 9,-32702; lfs f1,-7356(9); fsubs f1,f0,f1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CB8E4_0();
extern "C" void f_802CB8E4() {}
