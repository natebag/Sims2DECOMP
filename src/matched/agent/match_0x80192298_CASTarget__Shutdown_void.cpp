// 0x80192298 CASTarget::Shutdown(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 31,0x1630(30); cmpwi 31,0; bne 2f; lwz 4,0x1358(30); li 0,1; stw 0,0x1630(30); stw 31,0x1634(30); cmpwi 4,0; beq 0f; li 3,0; bl _s80192298_0; stw 31,0x1358(30); 0:; lwz 4,0x135c(30); cmpwi 4,0; beq 1f; li 3,1; bl _s80192298_1; stw 31,0x135c(30); 1:; li 3,5; lis 30,-32705; bl _s80192298_2; lwz 11,-26392(13); lfs f1,-15980(30); lwz 9,0x0(11); fmr f2,f1; lha 3,0x1a8(9); fmr f3,f2; lwz 0,0x1ac(9); fmr f4,f3; add 3,11,3; mtspr 8,0; blrl; lfs f1,-15980(30); lis 9,-32705; lis 11,-32705; lfs f3,-15976(9); lfs f4,-15972(11); fmr f2,f1; lwz 3,-26392(13); bl _s80192298_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80192298_0();
extern "C" void _s80192298_1();
extern "C" void _s80192298_2();
extern "C" void _s80192298_3();
extern "C" void f_80192298() {}
