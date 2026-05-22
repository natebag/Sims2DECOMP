// 0x8035DFB0 ERotDecomp::ResetEnd(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 10,-32702; lwz 9,0x18(30); lha 0,0x1c(30); addi 4,9,-1; lwz 11,0x10(30); mullw 4,4,0; lfs f0,0x2db8(10); lwz 0,0x4(30); addi 9,9,-2; lbz 5,0x1e(30); addi 11,11,-1; lwz 3,0x0(30); stw 9,0x14(30); add 4,0,4; extsb 5,5; stw 11,0xc(30); stfs f0,0x2c(30); bl _s8035DFB0_0; lwz 9,0xc(30); addi 9,9,-1; subf 9,3,9; stw 9,0x8(30); mr 3,30; bl _s8035DFB0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035DFB0_0();
extern "C" void _s8035DFB0_1();
extern "C" void f_8035DFB0() {}
