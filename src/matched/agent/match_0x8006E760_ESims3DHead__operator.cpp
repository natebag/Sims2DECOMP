// 0x8006E760 ESims3DHead::operator (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; bl _s8006E760_0; li 6,0; li 7,0; mr 4,29; li 5,16; bl _s8006E760_1; mr 30,3; mr 5,29; li 4,0; bl _s8006E760_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8006E760_0();
extern "C" void _s8006E760_1();
extern "C" void _s8006E760_2();
extern "C" void f_8006E760() {}
