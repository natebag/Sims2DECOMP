// 0x80006B00 ESimsApp::UpdateApt(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s80006B00_0; mr 30,3; mr 3,31; bl _s80006B00_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-112(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; addi 1,1,112; blr; blr"
extern "C" void _s80006B00_0();
extern "C" void _s80006B00_1();
extern "C" void f_80006B00() {}
