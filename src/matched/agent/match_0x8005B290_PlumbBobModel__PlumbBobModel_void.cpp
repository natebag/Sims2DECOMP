// 0x8005B290 PlumbBobModel::PlumbBobModel(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 10,-32707; lis 11,-32707; lfs f0,0x4314(11); mr 9,3; lfs f13,0x4310(10); addi 11,9,12; stfs f0,0x8(9); lis 10,-32696; stfs f13,0x4(9); li 0,0; stfs f13,0x0(9); stfs f0,0x4(11); stfs f0,0x8(11); stfs f0,0xc(9); lfs f13,0x55c0(10); stfs f0,0x34(9); stfs f13,0x18(9); stw 0,0x38(9); stfs f0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 0,0x28(9); stw 0,0x2c(9); stfs f0,0x30(9)"
extern "C" void f_8005B290() {}
