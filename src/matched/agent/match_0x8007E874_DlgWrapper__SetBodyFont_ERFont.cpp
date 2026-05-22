// 0x8007E874 DlgWrapper::SetBodyFont(ERFont (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0xac(3); lwz 30,0x64(9); addi 3,30,32; stw 4,0x30(3); bl _s8007E874_0; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007E874_0();
extern "C" void f_8007E874() {}
