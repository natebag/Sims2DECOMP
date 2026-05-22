// 0x801CEF8C O2TTarget::RestoreAudioOptions(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 30,-32697; lbz 0,-29740(13); addi 30,30,24012; lwz 9,0x148(30); stb 0,0x1c(9); lbz 4,-29740(13); lwz 3,-21492(13); extsb 4,4; bl _s801CEF8C_0; lwz 9,0x148(30); lbz 0,-29739(13); stb 0,0x1d(9); lbz 4,-29739(13); lwz 3,-21492(13); extsb 4,4; bl _s801CEF8C_1; lwz 9,0x148(30); lbz 0,-29738(13); stb 0,0x29(9); lbz 4,-29738(13); lwz 3,-21492(13); extsb 4,4; bl _s801CEF8C_2; lwz 9,0x148(30); lbz 0,-29737(13); stb 0,0x28(9); lbz 4,-29737(13); lwz 3,-21492(13); extsb 4,4; bl _s801CEF8C_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801CEF8C_0();
extern "C" void _s801CEF8C_1();
extern "C" void _s801CEF8C_2();
extern "C" void _s801CEF8C_3();
extern "C" void f_801CEF8C() {}
