// 0x802D79C4 ESemaphore::iRelease(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xc(3); lwz 0,0x8(3); cmpw 9,0; bge 0f; addi 3,3,12; bl _s802D79C4_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D79C4_0();
extern "C" void f_802D79C4() {}
