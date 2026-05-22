// 0x80366998 ERAmbientSound::ERAmbientSound(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr 9,3; li 0,0; lis 11,-32702; stw 0,0x24(9); lfs f0,0x31e4(11); addi 10,9,44; stw 0,0x28(9); stw 0,0x4(10); stfs f0,0x14(9); stb 0,0x21(9); stfs f0,0x0(9); stfs f0,0x4(9); stfs f0,0x8(9); stfs f0,0xc(9); stfs f0,0x10(9); stb 0,0x18(9); stb 0,0x19(9); stb 0,0x1a(9); stb 0,0x1b(9); stb 0,0x1c(9); stb 0,0x1d(9); stb 0,0x1e(9); stb 0,0x1f(9); stb 0,0x20(9); addi 1,1,16"
extern "C" void f_80366998() {}
