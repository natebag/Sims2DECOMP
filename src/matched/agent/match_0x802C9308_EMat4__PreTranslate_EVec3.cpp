// 0x802C9308 EMat4::PreTranslate(EVec3 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,3; mr 9,3; mtspr 9,0; 0:; lfs f0,0x10(9); lfs f12,0x4(4); lfs f11,0x0(4); lfs f9,0x0(9); fmuls f12,f12,f0; lfs f13,0x8(4); lfs f10,0x20(9); fmadds f11,f11,f9,f12; lfs f0,0x30(9); fmadds f13,f13,f10,f11; fadds f0,f0,f13; stfs f0,0x30(9); addi 9,9,4; bdnz 0b"
extern "C" void f_802C9308() {}
