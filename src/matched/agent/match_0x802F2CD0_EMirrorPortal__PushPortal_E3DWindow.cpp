// 0x802F2CD0 EMirrorPortal::PushPortal(E3DWindow (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 30,4; mr 6,3; lwz 11,0xa0(30); lwz 12,0xa4(30); addi 8,30,160; lwz 7,0x3c(6); addi 3,1,8; mr 5,8; stw 11,0x0(7); stw 12,0x4(7); lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x8(7); stw 10,0xc(7); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x10(7); stw 12,0x14(7); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x18(7); stw 10,0x1c(7); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x20(7); stw 12,0x24(7); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x28(7); stw 10,0x2c(7); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x30(7); stw 12,0x34(7); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x38(7); stw 10,0x3c(7); lwz 4,0x40(6); bl _s802F2CD0_0; mr 3,30; addi 4,1,8; bl _s802F2CD0_1; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s802F2CD0_0();
extern "C" void _s802F2CD0_1();
extern "C" void f_802F2CD0() {}
