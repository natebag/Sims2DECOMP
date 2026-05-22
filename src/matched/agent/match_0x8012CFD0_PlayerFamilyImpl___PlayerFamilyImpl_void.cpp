// 0x8012CFD0 PlayerFamilyImpl::~PlayerFamilyImpl(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,12872; mr 29,4; stw 9,0x0(30); addi 3,30,3292; li 4,2; bl _s8012CFD0_0; addi 3,30,200; li 4,2; bl _s8012CFD0_1; addi 3,30,56; li 4,2; bl _s8012CFD0_2; mr 3,30; mr 4,29; bl _s8012CFD0_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012CFD0_0();
extern "C" void _s8012CFD0_1();
extern "C" void _s8012CFD0_2();
extern "C" void _s8012CFD0_3();
extern "C" void f_8012CFD0() {}
