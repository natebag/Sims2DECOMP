// 0x802D10C4 FPHeap::ValidatePools(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-21320(13); bl _s802D10C4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D10C4_0();
extern "C" void f_802D10C4() {}
