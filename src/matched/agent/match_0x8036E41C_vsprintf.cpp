// 0x8036E41C vsprintf (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stw 0,0x6c(1); lwz 10,-27948(13); lis 9,32767; mr 11,3; ori 9,9,65535; li 0,520; stw 9,0x1c(1); sth 0,0x14(1); addi 3,1,8; stw 9,0x10(1); stw 11,0x18(1); stw 10,0x64(1); stw 11,0x8(1); bl _s8036E41C_0; lwz 9,0x8(1); li 0,0; stb 0,0x0(9); lwz 0,0x6c(1); mtspr 8,0; addi 1,1,104"
extern "C" void _s8036E41C_0();
extern "C" void f_8036E41C() {}
