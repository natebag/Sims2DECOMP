// 0x8014754C StackElem::GetTreeName(StringBuffer (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x10(3); mr 30,4; cmpwi 31,0; beq 0f; bl _s8014754C_0; mr 4,3; mr 5,30; mr 3,31; bl _s8014754C_1; b 1f; 0:; lis 4,-32706; mr 3,30; addi 4,4,-10308; bl _s8014754C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014754C_0();
extern "C" void _s8014754C_1();
extern "C" void _s8014754C_2();
extern "C" void f_8014754C() {}
