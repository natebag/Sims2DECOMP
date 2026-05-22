// 0x80310340 EResourceLoaderImpl::Shutdown(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; lwz 9,0x0(30); addi 31,30,852; li 29,2; lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; mtspr 8,0; blrl; addi 3,30,8; bl _s80310340_0; addi 3,30,888; bl _s80310340_1; 0:; bl _s80310340_2; lwz 4,0x0(31); bl _s80310340_3; stw 28,0x0(31); addic. 29,29,-1; addi 31,31,4; bne 0b; stw 29,0x3e4(30); addi 3,30,8; stw 29,0x350(30); bl _s80310340_4; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80310340_0();
extern "C" void _s80310340_1();
extern "C" void _s80310340_2();
extern "C" void _s80310340_3();
extern "C" void _s80310340_4();
extern "C" void f_80310340() {}
