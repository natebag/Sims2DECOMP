// 0x8022E67C EIStaticSubModel::GetBoundSphere(EBoundSphere (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 9,3,128; lwz 0,0x80(3); lwz 11,0x4(9); lwz 10,0x8(9); stw 0,0x0(4); stw 11,0x4(4); stw 10,0x8(4); lfs f0,0xc(9); stfs f0,0xc(4)"
extern "C" void f_8022E67C() {}
