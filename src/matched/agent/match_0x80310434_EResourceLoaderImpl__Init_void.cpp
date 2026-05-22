// 0x80310434 EResourceLoaderImpl::Init(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; stw 28,0x3e4(30); addi 29,30,8; bl _s80310434_0; li 4,1500; addi 3,30,888; bl _s80310434_1; lis 9,-32702; li 5,0; addi 9,9,1064; li 6,0; stw 9,0x32c(29); li 4,17; ori 5,5,32768; mr 3,29; bl _s80310434_2; mr 3,29; bl _s80310434_3; li 0,1; stw 28,0x3e8(30); stw 0,0x350(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80310434_0();
extern "C" void _s80310434_1();
extern "C" void _s80310434_2();
extern "C" void _s80310434_3();
extern "C" void f_80310434() {}
