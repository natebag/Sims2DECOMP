// 0x8013DAD0 SeqResFile::~SeqResFile(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 29,3; addi 9,9,17672; mr 28,4; stw 9,0xc(29); bl _s8013DAD0_0; addic. 30,3,-1; blt 2f; 0:; extsh 4,30; mr 3,29; bl _s8013DAD0_1; mr 31,3; mr 3,29; mr 4,31; bl _s8013DAD0_2; cmpwi 31,0; beq 1f; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 1:; addic. 30,30,-1; bge 0b; 2:; mr 3,29; mr 4,28; bl _s8013DAD0_3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8013DAD0_0();
extern "C" void _s8013DAD0_1();
extern "C" void _s8013DAD0_2();
extern "C" void _s8013DAD0_3();
extern "C" void f_8013DAD0() {}
