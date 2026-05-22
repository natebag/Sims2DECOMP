// 0x802BCA84 EAStringC::Format(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stw 0,0x94(1); lis 12,512; addi 0,1,152; addi 11,1,8; stw 0,0x84(1); stw 11,0x88(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 12,0x80(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; addi 11,1,128; addi 9,1,112; lwz 10,0x8(11); mr 5,9; lwz 0,0x4(11); stw 12,0x70(1); stw 0,0x4(9); stw 10,0x8(9); bl _s802BCA84_0; lwz 0,0x94(1); mtspr 8,0; addi 1,1,144"
extern "C" void _s802BCA84_0();
extern "C" void f_802BCA84() {}
