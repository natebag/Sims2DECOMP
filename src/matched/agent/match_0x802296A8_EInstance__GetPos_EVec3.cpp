// 0x802296A8 EInstance::GetPos(EVec3 (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lfs f0,-6100(9); stfs f0,0x0(4); stfs f0,0x8(4); stfs f0,0x4(4)"
extern "C" void f_802296A8() {}
