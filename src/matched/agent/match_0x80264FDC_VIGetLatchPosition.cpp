// 0x80264FDC __VIGetLatchPosition (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,0; stw 0,0x4(1); stwu 1,-8(1); bne 0f; addi 3,4,0; addi 4,5,0; bl _s80264FDC_0; b 1f; 0:; addi 3,4,0; addi 4,5,0; bl _s80264FDC_1; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80264FDC_0();
extern "C" void _s80264FDC_1();
extern "C" void f_80264FDC() {}
