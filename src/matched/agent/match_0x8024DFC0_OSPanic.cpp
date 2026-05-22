// 0x8024DFC0 OSPanic (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-144(1); stw 31,0x8c(1); stw 30,0x88(1); stw 29,0x84(1); stw 28,0x80(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; stw 3,0x8(1); addi 28,3,0; addi 30,4,0; stw 4,0xc(1); addi 29,5,0; stw 5,0x10(1); stw 6,0x14(1); lis 6,-32700; addi 31,6,-19512; stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bl _s8024DFC0_0; lis 0,768; stw 0,0x74(1); addi 0,1,152; addi 4,1,116; stw 0,0x78(1); addi 0,1,8; addi 3,29,0; stw 0,0x7c(1); bl _s8024DFC0_1; addi 3,31,0; crxor 6,6,6; addi 4,28,0; addi 5,30,0; bl _s8024DFC0_2; addi 3,31,24; crxor 6,6,6; bl _s8024DFC0_3; li 30,0; bl _s8024DFC0_4; mr 29,3; b 2f; 1:; lwz 5,0x0(29); mr 4,29; lwz 6,0x4(29); addi 3,31,64; crxor 6,6,6; bl _s8024DFC0_5; lwz 29,0x0(29); 2:; cmplwi 29,0; beq 3f; addis 0,29,1; cmplwi 0,65535; beq 3f; cmplwi 30,16; addi 30,30,1; blt 1b; 3:; bl _s8024DFC0_6; lwz 0,0x94(1); lwz 31,0x8c(1); lwz 30,0x88(1); lwz 29,0x84(1); lwz 28,0x80(1); addi 1,1,144; mtspr 8,0"
extern "C" void _s8024DFC0_0();
extern "C" void _s8024DFC0_1();
extern "C" void _s8024DFC0_2();
extern "C" void _s8024DFC0_3();
extern "C" void _s8024DFC0_4();
extern "C" void _s8024DFC0_5();
extern "C" void _s8024DFC0_6();
extern "C" void f_8024DFC0() {}
