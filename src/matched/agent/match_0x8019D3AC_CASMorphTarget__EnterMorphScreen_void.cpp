// 0x8019D3AC CASMorphTarget::EnterMorphScreen(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x84(31); bl _s8019D3AC_0; addi 11,31,156; li 0,288; 0:; lwz 9,0x0(3); addic. 0,0,-24; stw 9,0x0(11); lwz 9,0x4(3); stw 9,0x4(11); lwz 9,0x8(3); stw 9,0x8(11); lwz 9,0xc(3); stw 9,0xc(11); lwz 9,0x10(3); stw 9,0x10(11); lwz 9,0x14(3); addi 3,3,24; stw 9,0x14(11); addi 11,11,24; bne 0b; lwz 9,0x0(3); li 0,1; stw 9,0x0(11); stw 0,0x1c0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8019D3AC_0();
extern "C" void f_8019D3AC() {}
