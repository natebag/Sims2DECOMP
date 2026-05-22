// 0x80034690 ESim::CreateThumbnail(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-560(1); mfspr 0,8; stmw 30,0x228(1); stw 0,0x234(1); mr 30,3; bl _s80034690_0; cmpwi 3,0; beq 0f; lis 3,-32697; addi 3,3,14696; bl _s80034690_1; mr 3,30; bl _s80034690_2; 0:; addi 3,1,8; bl _s80034690_3; mr 3,30; bl _s80034690_4; mr 4,3; addi 3,1,8; bl _s80034690_5; lwz 4,0x63c(30); addi 3,1,8; bl _s80034690_6; addi 3,1,8; bl _s80034690_7; lwz 11,0x3d0(30); mr 30,3; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x368(9); lwz 0,0x36c(9); add 3,10,3; mtspr 8,0; blrl; mr 4,30; bl _s80034690_8; addi 3,1,8; li 4,2; bl _s80034690_9; lwz 0,0x234(1); mtspr 8,0; lmw 30,0x228(1); addi 1,1,560"
extern "C" void _s80034690_0();
extern "C" void _s80034690_1();
extern "C" void _s80034690_2();
extern "C" void _s80034690_3();
extern "C" void _s80034690_4();
extern "C" void _s80034690_5();
extern "C" void _s80034690_6();
extern "C" void _s80034690_7();
extern "C" void _s80034690_8();
extern "C" void _s80034690_9();
extern "C" void f_80034690() {}
