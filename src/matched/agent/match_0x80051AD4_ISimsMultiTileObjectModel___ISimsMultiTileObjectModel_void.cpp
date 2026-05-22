// 0x80051AD4 ISimsMultiTileObjectModel::~ISimsMultiTileObjectModel(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; lis 11,-32698; mr 31,3; mr 30,4; addi 9,9,-17000; addi 11,11,-16944; stw 9,0x320(31); stw 11,0x0(31); li 4,0; bl _s80051AD4_0; andi. 0,30,1; beq 0f; bl _s80051AD4_1; mr 4,31; bl _s80051AD4_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80051AD4_0();
extern "C" void _s80051AD4_1();
extern "C" void _s80051AD4_2();
extern "C" void f_80051AD4() {}
