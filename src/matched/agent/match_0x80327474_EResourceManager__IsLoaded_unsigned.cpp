// 0x80327474 EResourceManager::IsLoaded(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; stw 30,0x8(1); li 4,-1; lwz 9,0x0(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; li 5,0; mr 4,29; addi 3,30,3336; bl _s80327474_0; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80327474_0();
extern "C" void f_80327474() {}
