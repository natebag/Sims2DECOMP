// 0x8014349C SlotDescriptor::SlotDescriptor(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); lis 9,-32706; mr 30,3; lfs f0,-10440(9); li 0,-1; sth 0,0x0(30); addi 3,1,8; stfs f0,0xc(30); stfs f0,0x4(30); stfs f0,0x8(30); bl _s8014349C_0; lwz 27,0x18(1); li 0,0; lwz 28,0x1c(1); lis 9,-32698; lwz 29,0x20(1); addi 9,9,18992; lwz 4,0x24(1); mr 3,30; lwz 11,0x28(1); lwz 10,0x2c(1); lwz 8,0x30(1); lwz 7,0x34(1); lfs f0,0x38(1); lwz 6,0x3c(1); lwz 5,0x40(1); stw 27,0x1c(30); stw 28,0x20(30); stw 29,0x24(30); stw 4,0x28(30); stw 11,0x2c(30); stw 10,0x30(30); stw 8,0x34(30); stw 7,0x38(30); stfs f0,0x3c(30); stw 6,0x40(30); stw 5,0x44(30); stw 0,0x18(30); stw 9,0x8(1); stw 0,0x10(30); stw 0,0x14(30); lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"
extern "C" void _s8014349C_0();
extern "C" void f_8014349C() {}
