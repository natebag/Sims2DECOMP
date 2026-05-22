// 0x802C9454 EMat4::operator=(float) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; stfs f1,0x3c(9); stfs f1,0x0(9); stfs f1,0x4(9); stfs f1,0x8(9); stfs f1,0xc(9); stfs f1,0x10(9); stfs f1,0x14(9); stfs f1,0x18(9); stfs f1,0x1c(9); stfs f1,0x20(9); stfs f1,0x24(9); stfs f1,0x28(9); stfs f1,0x2c(9); stfs f1,0x30(9); stfs f1,0x34(9); stfs f1,0x38(9)"
extern "C" void f_802C9454() {}
