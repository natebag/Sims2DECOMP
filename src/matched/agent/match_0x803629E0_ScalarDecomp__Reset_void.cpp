// 0x803629E0 ScalarDecomp::Reset(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 9,-32702; lfs f0,0x2f0c(9); li 11,0; lha 0,0x1c(30); lwz 4,0x4(30); lbz 5,0x1e(30); lwz 3,0x0(30); add 4,4,0; extsb 5,5; stw 11,0xc(30); stfs f0,0x28(30); stw 11,0x8(30); bl _s803629E0_0; addi 3,3,1; stw 3,0x10(30); mr 3,30; bl _s803629E0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803629E0_0();
extern "C" void _s803629E0_1();
extern "C" void f_803629E0() {}
