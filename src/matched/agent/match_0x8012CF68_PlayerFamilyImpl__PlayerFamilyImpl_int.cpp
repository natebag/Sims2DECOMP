// 0x8012CF68 PlayerFamilyImpl::PlayerFamilyImpl(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,56; bl _s8012CF68_0; lis 9,-32698; mr 3,29; addi 9,9,12872; stw 9,0x0(30); bl _s8012CF68_1; addi 3,30,200; bl _s8012CF68_2; addi 3,30,3292; bl _s8012CF68_3; mr 3,29; bl _s8012CF68_4; li 0,0; mr 3,30; stw 0,0xd64(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012CF68_0();
extern "C" void _s8012CF68_1();
extern "C" void _s8012CF68_2();
extern "C" void _s8012CF68_3();
extern "C" void _s8012CF68_4();
extern "C" void f_8012CF68() {}
