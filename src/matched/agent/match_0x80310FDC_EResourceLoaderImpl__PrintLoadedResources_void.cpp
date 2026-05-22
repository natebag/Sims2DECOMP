// 0x80310FDC EResourceLoaderImpl::PrintLoadedResources(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; lwz 9,0x35c(30); addi 0,30,860; stw 0,0x8(1); lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 30,0x348(30); cmpwi 30,0; beq 1f; 0:; mr 3,30; bl _s80310FDC_0; lwz 30,0xd04(30); cmpwi 30,0; bne 0b; 1:; bl _s80310FDC_1; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80310FDC_0();
extern "C" void _s80310FDC_1();
extern "C" void f_80310FDC() {}
