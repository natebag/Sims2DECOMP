// 0x8000FED4 AptShaderWord::AptShaderWord(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32698; mr 11,3; li 0,0; addi 9,9,-21112; stw 9,0x2c(11); lis 8,-32707; stw 0,0x18(11); lis 7,-32707; stw 0,0x0(11); lis 10,-32698; stw 0,0x8(11); addi 10,10,-21160; stw 0,0xc(11); stw 0,0x10(11); stw 0,0x14(11); lfs f0,-10072(8); stfs f0,0xc(1); stfs f0,0x8(1); lwz 0,0xc(1); lwz 9,0x8(1); stw 0,0x20(11); stw 9,0x1c(11); lfs f0,-10068(7); stw 10,0x2c(11); stfs f0,0x8(1); stfs f0,0xc(1); lwz 0,0x8(1); lwz 9,0xc(1); stw 0,0x24(11); stw 9,0x28(11); stfs f0,0x30(11); addi 1,1,16"
extern "C" void f_8000FED4() {}
