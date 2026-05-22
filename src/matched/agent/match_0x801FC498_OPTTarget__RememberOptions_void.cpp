// 0x801FC498 OPTTarget::RememberOptions(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32697; addi 11,11,24012; lwz 9,0x148(11); lbz 0,0x1c(9); stb 0,0x84(3); lwz 9,0x148(11); lbz 0,0x1d(9); stb 0,0x85(3); lwz 9,0x148(11); lbz 0,0x1f(9); stb 0,0x86(3); lwz 9,0x148(11); lbz 0,0x20(9); stb 0,0x87(3); lwz 9,0x148(11); lwz 0,0x4(9); stw 0,0x88(3); lwz 9,0x148(11); lwz 0,0x0(9); stw 0,0x8c(3); lwz 9,0x148(11); lwz 0,0x14(9); stw 0,0x90(3); lwz 9,0x148(11); lwz 0,0x18(9); stw 0,0x94(3); lwz 9,0x148(11); lwz 0,0x10(9); stw 0,0x98(3)"
extern "C" void f_801FC498() {}
