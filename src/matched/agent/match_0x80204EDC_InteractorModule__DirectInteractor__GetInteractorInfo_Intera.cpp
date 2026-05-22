// 0x80204EDC InteractorModule::DirectInteractor::GetInteractorInfo(InteractorModule::InteractorInfo (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x78(3); cmpwi 9,0; beq 0f; lfs f0,0x0(9); stfs f0,0x0(4); lfs f13,0x4(9); stfs f13,0x4(4); 0:; lwz 0,0x54(3); lwz 9,0x50(3); stw 0,0xc(4); stw 9,0x8(4)"
extern "C" void f_80204EDC() {}
