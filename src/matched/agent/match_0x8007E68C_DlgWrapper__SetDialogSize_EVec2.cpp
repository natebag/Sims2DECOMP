// 0x8007E68C DlgWrapper::SetDialogSize(EVec2 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(4); lwz 9,0x4(4); stw 0,0xc4(3); stw 9,0xc8(3); lwz 11,0xac(3); lwz 0,0x4(4); lwz 9,0x64(11); lwz 10,0x0(4); stw 0,0x30(9); addi 3,9,32; stw 10,0x2c(9); bl _s8007E68C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8007E68C_0();
extern "C" void f_8007E68C() {}
