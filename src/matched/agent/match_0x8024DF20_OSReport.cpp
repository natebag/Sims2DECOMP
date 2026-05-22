// 0x8024DF20 OSReport (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-120(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; stw 3,0x8(1); lis 0,256; stw 4,0xc(1); addi 4,1,108; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 0,0x6c(1); addi 0,1,128; stw 0,0x70(1); addi 0,1,8; stw 0,0x74(1); bl _s8024DF20_0; lwz 0,0x7c(1); addi 1,1,120; mtspr 8,0"
extern "C" void _s8024DF20_0();
extern "C" void f_8024DF20() {}
