// 0x8005892C OptionsRecon::ResetToDefaults(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; li 11,10; li 9,1; li 10,-1; stw 0,0x24(3); stb 11,0x1e(3); stb 10,0x54(3); stw 9,0x14(3); stw 9,0x0(3); stw 9,0x4(3); stw 9,0x8(3); stw 0,0xc(3); stw 0,0x10(3); stb 11,0x1c(3); stb 11,0x1d(3); stb 11,0x28(3); stb 11,0x29(3); stb 0,0x1f(3); stb 0,0x20(3); stw 0,0xe8(3); stw 0,0xec(3); stw 0,0xf0(3); stw 0,0x18(3)"
extern "C" void f_8005892C() {}
