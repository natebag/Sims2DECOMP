// 0x801FC510 OPTTarget::RestoreOptions(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 30,-32697; mr 29,3; addi 30,30,24012; lbz 0,0x84(29); lwz 9,0x148(30); stb 0,0x1c(9); lbz 4,0x84(29); lwz 3,-21492(13); extsb 4,4; bl _s801FC510_0; lwz 9,0x148(30); lbz 0,0x85(29); stb 0,0x1d(9); lbz 4,0x85(29); lwz 3,-21492(13); extsb 4,4; bl _s801FC510_1; lwz 11,0x148(30); mr 3,30; lbz 0,0x86(29); stb 0,0x1f(11); lwz 9,0x148(30); lbz 0,0x87(29); stb 0,0x20(9); bl _s801FC510_2; lwz 9,0x148(30); lwz 0,0x88(29); stw 0,0x4(9); lwz 11,0x148(30); lwz 0,0x8c(29); stw 0,0x0(11); lwz 9,0x148(30); lwz 0,0x90(29); stw 0,0x14(9); lwz 0,0x94(29); lwz 11,0x148(30); stw 0,0x18(11); lwz 9,0x148(30); lwz 0,0x98(29); stw 0,0x10(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801FC510_0();
extern "C" void _s801FC510_1();
extern "C" void _s801FC510_2();
extern "C" void f_801FC510() {}
