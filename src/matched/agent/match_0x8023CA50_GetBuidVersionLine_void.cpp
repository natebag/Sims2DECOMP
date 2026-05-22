// 0x8023CA50 GetBuidVersionLine(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 30,-32695; lis 4,-32704; lis 5,-32700; addi 4,4,-1012; addi 5,5,-24348; addi 3,30,-528; crxor 6,6,6; bl _s8023CA50_0; addi 3,30,-528; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023CA50_0();
extern "C" void f_8023CA50() {}
