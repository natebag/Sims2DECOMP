// 0x80311260 EResourceLoaderImpl::FreeUnreferencedResources(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; addi 0,30,860; lwz 9,0x35c(30); stw 0,0x8(1); li 4,-1; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; mr 3,30; mr 4,29; bl _s80311260_0; mr. 3,3; bne 0f; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; b 1f; 0:; bl _s80311260_1; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80311260_0();
extern "C" void _s80311260_1();
extern "C" void f_80311260() {}
