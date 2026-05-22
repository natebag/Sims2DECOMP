// 0x8024D9C4 OSInitContext (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024D9A0" lines="stw 4,0x198(3); stw 5,0x4(3); li 11,0; ori 11,11,36914; stw 11,0x19c(3); li 0,0; stw 0,0x80(3); stw 0,0x8c(3); stw 2,0x8(3); stw 13,0x34(3); stw 0,0xc(3); stw 0,0x10(3); stw 0,0x14(3); stw 0,0x18(3); stw 0,0x1c(3); stw 0,0x20(3); stw 0,0x24(3); stw 0,0x28(3); stw 0,0x2c(3); stw 0,0x30(3); stw 0,0x38(3); stw 0,0x3c(3); stw 0,0x40(3); stw 0,0x44(3); stw 0,0x48(3); stw 0,0x4c(3); stw 0,0x50(3); stw 0,0x54(3); stw 0,0x58(3); stw 0,0x5c(3); stw 0,0x60(3); stw 0,0x64(3); stw 0,0x68(3); stw 0,0x6c(3); stw 0,0x70(3); stw 0,0x74(3); stw 0,0x78(3); stw 0,0x7c(3); stw 0,0x1a4(3); stw 0,0x1a8(3); stw 0,0x1ac(3); stw 0,0x1b0(3); stw 0,0x1b4(3); stw 0,0x1b8(3); stw 0,0x1bc(3); stw 0,0x1c0(3)"
extern "C" void f_8024D9A0();
extern "C" void f_8024D9C4() {}
