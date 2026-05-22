// 0x802D09AC EAHeap::SetNextCheckPoint(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802D09AC_0; addi 3,3,1; stw 3,-26860(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D09AC_0();
extern "C" void f_802D09AC() {}
