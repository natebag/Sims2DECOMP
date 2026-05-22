// 0x80175180 CasSimState::HandleEventMorphSim(CasEventMorphSimS2C (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(4); cmpwi 0,3; beq 4f; bgt 0f; cmpwi 0,1; beq 2f; bgt 3f; cmpwi 0,0; beq 1f; blr; 0:; cmpwi 0,5; beq 6f; blt 5f; cmpwi 0,6; beq 7f; cmpwi 0,7; beq 8f; blr; 1:; lfs f0,0xc(4); stfs f0,0x100(3); blr; 2:; lfs f0,0xc(4); stfs f0,0x104(3); blr; 3:; lfs f0,0xc(4); stfs f0,0x10c(3); blr; 4:; lfs f0,0xc(4); stfs f0,0x108(3); blr; 5:; lfs f0,0xc(4); stfs f0,0x110(3); blr; 6:; lfs f0,0xc(4); stfs f0,0x114(3); blr; 7:; lfs f0,0xc(4); stfs f0,0x118(3); blr; 8:; lfs f0,0xc(4); stfs f0,0x11c(3)"
extern "C" void f_80175180() {}
