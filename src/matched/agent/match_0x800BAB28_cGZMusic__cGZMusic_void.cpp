// 0x800BAB28 cGZMusic::cGZMusic(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 11,-32706; mr 30,3; lfs f0,-25288(11); lis 9,-32698; lwz 3,-24468(13); li 8,1; addi 9,9,-3872; li 0,1024; li 11,512; li 10,0; stw 9,0x0(30); mr 4,30; stw 0,0x14(30); stfs f0,0x1c(30); stw 11,0x18(30); stw 10,0x8(30); stw 8,0x20(30); stw 8,0x4(30); bl _s800BAB28_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BAB28_0();
extern "C" void f_800BAB28() {}
