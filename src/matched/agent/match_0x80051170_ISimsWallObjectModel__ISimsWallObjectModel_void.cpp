// 0x80051170 ISimsWallObjectModel::ISimsWallObjectModel(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80051170_0; lis 9,-32698; lis 11,-32698; addi 9,9,-16448; addi 11,11,-16392; stw 9,0x320(30); mr 3,30; stw 11,0x0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80051170_0();
extern "C" void f_80051170() {}
