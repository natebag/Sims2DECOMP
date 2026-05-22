// 0x800B1D94 ChainResFile::ChainResFile(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; bl _s800B1D94_0; lis 9,-32698; li 8,8; addi 9,9,-5448; mtspr 9,8; stw 9,0xc(31); li 0,0; li 10,1; addi 11,31,16; 0:; stw 0,0x0(11); stw 0,0x4(11); stw 0,0x8(11); stw 0,0x10(11); stw 10,0x14(11); addi 11,11,24; bdnz 0b; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800B1D94_0();
extern "C" void f_800B1D94() {}
