// 0x800B9FB8 cGZSnd::cGZSnd(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 11,-32706; mr 30,3; lfs f0,-25360(11); lis 9,-32698; lwz 3,-24468(13); addi 9,9,-3704; li 10,1024; li 0,1; li 11,512; stw 9,0x0(30); stfs f0,0x30(30); mr 4,30; stw 0,0x4(30); stw 11,0x24(30); stw 10,0x38(30); stw 10,0x20(30); bl _s800B9FB8_0; lis 9,-32706; mr 3,30; lfs f0,-25356(9); stfs f0,0x2c(30); stfs f0,0x28(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B9FB8_0();
extern "C" void f_800B9FB8() {}
