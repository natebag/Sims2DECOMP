// 0x801096C4 cXObjectImpl::Simulate(int) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 3,0x0(30); bl _s801096C4_0; mr. 29,3; beq 2f; addi 31,30,40; li 4,25; mr 3,31; bl _s801096C4_1; lha 0,0x0(3); cmpwi 0,0; beq 0f; li 4,25; mr 3,31; bl _s801096C4_2; lhz 5,0x0(3); li 4,25; mr 3,31; addi 5,5,-1; extsh 5,5; bl _s801096C4_3; 0:; addi 9,30,176; lwz 31,0xb0(30); lwz 0,0x4(9); mr 30,9; cmpw 31,0; beq 2f; 1:; mr 3,31; bl _s801096C4_4; addi 31,31,108; lwz 0,0x4(30); cmpw 31,0; bne 1b; 2:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801096C4_0();
extern "C" void _s801096C4_1();
extern "C" void _s801096C4_2();
extern "C" void _s801096C4_3();
extern "C" void _s801096C4_4();
extern "C" void f_801096C4() {}
