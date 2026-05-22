// 0x802C9730 EMat4::Translate(EVec3 (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s802C9730_0; lfs f13,0x0(29); addi 9,30,48; mr 3,30; stfs f13,0x30(30); lfs f0,0x4(29); stfs f0,0x4(9); lfs f13,0x8(29); stfs f13,0x8(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C9730_0();
extern "C" void f_802C9730() {}
