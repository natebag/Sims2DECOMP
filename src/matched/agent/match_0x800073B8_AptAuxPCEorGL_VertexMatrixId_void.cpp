// 0x800073B8 AptAuxPCEorGL_VertexMatrixId(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,-6224; bl _s800073B8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800073B8_0();
extern "C" void f_800073B8() {}
