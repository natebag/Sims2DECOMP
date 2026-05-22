// 0x8007E808 DlgWrapper::SetTitleFontSize(float) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0xac(3); lwz 30,0x60(9); addi 3,30,32; stfs f1,0x34(3); bl _s8007E808_0; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007E808_0();
extern "C" void f_8007E808() {}
