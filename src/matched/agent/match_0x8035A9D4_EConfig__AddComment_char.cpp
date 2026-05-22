// 0x8035A9D4 EConfig::AddComment(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 29,4; li 3,4; bl _s8035A9D4_0; mr 30,3; bl _s8035A9D4_1; lis 4,-32702; mr 3,30; addi 4,4,11472; bl _s8035A9D4_2; mr 4,29; mr 3,30; bl _s8035A9D4_3; mr 4,30; addi 3,28,8; bl _s8035A9D4_4; li 0,1; stw 0,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035A9D4_0();
extern "C" void _s8035A9D4_1();
extern "C" void _s8035A9D4_2();
extern "C" void _s8035A9D4_3();
extern "C" void _s8035A9D4_4();
extern "C" void f_8035A9D4() {}
