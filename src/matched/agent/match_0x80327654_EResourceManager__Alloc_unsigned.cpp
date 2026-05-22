// 0x80327654 EResourceManager::Alloc(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0xd1c(3); mr 29,4; mr 30,5; lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; mr 4,29; mr 5,30; li 6,0; li 7,0; bl _s80327654_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80327654_0();
extern "C" void f_80327654() {}
