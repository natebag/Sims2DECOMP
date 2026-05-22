// 0x80310588 EResourceLoaderImpl::AddManager(EResourceManager (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 29,4; addi 0,31,860; lwz 9,0x35c(31); stw 0,0x8(1); li 4,-1; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; addi 11,31,840; lwz 0,0x4(11); stw 0,0xd00(29); lwz 9,0x4(11); cmpwi 9,0; beq 0f; stw 29,0xd04(9); b 1f; 0:; stw 29,0x348(31); 1:; li 0,0; addi 3,1,16; stw 0,0xd04(29); mr 30,3; stw 29,0x4(11); lwz 4,0x40(29); bl _s80310588_0; mr 4,30; mr 3,31; bl _s80310588_1; mr 29,3; lwz 4,0x10(1); mr 3,30; bl _s80310588_2; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80310588_0();
extern "C" void _s80310588_1();
extern "C" void _s80310588_2();
extern "C" void f_80310588() {}
