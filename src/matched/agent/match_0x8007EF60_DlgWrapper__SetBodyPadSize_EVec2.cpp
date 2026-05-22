// 0x8007EF60 DlgWrapper::SetBodyPadSize(EVec2 (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0xac(3); lwz 0,0x4(4); lwz 9,0x64(11); lwz 10,0x0(4); stw 0,0x38(9); addi 3,9,32; stw 10,0x34(9); bl _s8007EF60_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8007EF60_0();
extern "C" void f_8007EF60() {}
