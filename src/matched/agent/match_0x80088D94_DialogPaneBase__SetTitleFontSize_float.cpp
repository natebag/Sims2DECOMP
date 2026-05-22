// 0x80088D94 DialogPaneBase::SetTitleFontSize(float) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0x60(3); addi 3,30,32; stfs f1,0x34(3); bl _s80088D94_0; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80088D94_0();
extern "C" void f_80088D94() {}
