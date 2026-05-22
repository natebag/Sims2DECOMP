// 0x800519D8 _Default2dArrayFree(void (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f30,0x138(1); lfd f31,0x140(1); mtcrf 8,12; addi 1,1,328; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800519D8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800519D8_0();
extern "C" void f_800519D8() {}
